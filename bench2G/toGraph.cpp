//将benchmark格式的电路转换为图结构
//转成的图是用来做链路预测的，参考MUXlink的实现方法
#include<bits/stdc++.h>
using namespace std;

map<string,string> featsMap;
vector<int> InputGates;   //存储input门，方便确定门在图中的深度
vector<int> count;      //gate对应的id编号
vector<string> function;     //buf,MUX,and....., 包括input但没有output

static int ID=0;
//int sum=0;      //统计总共有多少output

int Graph[5000][5000];   //图的邻接矩阵

map<string,int> hs;  //存放gate名字到id的映射

string keyInputBits="101111001101011000001011000111100011101011110100101010010001110101011101010100101000001101000010000110001110100010011101011111111110110101100101110001010101011110001010000010111110011011010111110011010011100000001110010101010011001000111001001100001011100100000100000100000110011110100111101110010000000001101010001"; //58个  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// 'xor': [0 1 0 0 0 0 0 0 0] 
// 'XOR': [0 1 0 0 0 0 0 0 0] 
// 'OR':  [0 0 1 0 0 0 0 0 0] 
// 'or':  [0 0 1 0 0 0 0 0 0] 
// 'XNOR':[0 0 0 1 0 0 0 0 0] 
// 'xnor':[0 0 0 1 0 0 0 0 0] 
// 'and': [0 0 0 0 1 0 0 0 0] 
// 'AND': [0 0 0 0 1 0 0 0 0] 
// 'nand':[0 0 0 0 0 1 0 0 0] 
// 'NAND':[0 0 0 0 0 1 0 0 0] 
// 'buf': [0 0 0 0 0 0 0 1 0] 
// 'BUF': [0 0 0 0 0 0 0 1 0] 
// 'not': [0 0 0 0 0 0 1 0 0] 
// 'NOT': [0 0 0 0 0 0 1 0 0] 
// 'mux': [0 0 0 0 0 0 0 0 1] 
// 'MUX': [0 0 0 0 0 0 0 0 1] 
// 'nor': [1 0 0 0 0 0 0 0 0] 
// 'NOR': [1 0 0 0 0 0 0 0 0]

string trim(const string& str) {
	string::size_type pos = str.find_first_not_of(' ');
	if (pos == string::npos) {  //若找不到空格
		return str;
	}
	string::size_type pos2 = str.find_last_not_of(' ');
	if (pos2 != string::npos)
		return str.substr(pos, pos2 - pos + 1); //子串：第一个非空格作为起始位置			                                        // 字符个数：pos2-pos+1
	return str.substr(pos);
}

vector<string> spiltD(string str){           //按逗号分隔
    vector<string> ret;
    string temp="";
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]==' ')continue;
        if(str[i]==','){
            ret.push_back(temp);
            temp="";
        }else{
            temp.push_back(str[i]);
        }
    }
    if(!temp.empty()){
        ret.push_back(temp);
    }
    return ret;
}

vector<string> parase(string line){      //返回的string 数组中第一个门是输出(=前的)，后面的全是输入
    vector<string> ret;
    int index = line.find("=");
    if(index<line.length()){
        string in=line.substr(0,index);
        ret.push_back(trim(in));
    }

    int beg=line.find("(");
    int end=line.find(")");
    string out=line.substr(beg+1,end-beg-1);

    vector<string> outputs=spiltD(trim(out));
    for(int i=0;i<outputs.size();i++){
        ret.push_back(trim(outputs[i]));
    }

    return ret;
}


int main(){
    //初始化特征
    featsMap["xor"]="0 1 0 0 0 0 0 0 0";
    featsMap["XOR"]="0 1 0 0 0 0 0 0 0";
    featsMap["OR"]="0 0 1 0 0 0 0 0 0";
    featsMap["or"]="0 0 1 0 0 0 0 0 0";
    featsMap["XNOR"]="0 0 0 1 0 0 0 0 0";
    featsMap["xnor"]="0 0 0 1 0 0 0 0 0";
    featsMap["and"]="0 0 0 0 1 0 0 0 0";
    featsMap["AND"]="0 0 0 0 1 0 0 0 0";
    featsMap["nand"]="0 0 0 0 0 1 0 0 0";
    featsMap["NAND"]="0 0 0 0 0 1 0 0 0";
    featsMap["buf"]="0 0 0 0 0 0 0 1 0";
    featsMap["BUF"]="0 0 0 0 0 0 0 1 0";
    featsMap["not"]="0 0 0 0 0 0 1 0 0";
    featsMap["NOT"]="0 0 0 0 0 0 1 0 0";
    featsMap["mux"]="0 0 0 0 0 0 0 0 1";
    featsMap["MUX"]="0 0 0 0 0 0 0 0 1";
    featsMap["nor"]="1 0 0 0 0 0 0 0 0";
    featsMap["NOR"]="1 0 0 0 0 0 0 0 0";

    memset(Graph,0,sizeof(Graph));

    ifstream fin("/home/lan/bench2G/c7552_locked.bench");
    ofstream f_feat("/home/lan/bench2G/result/feat.txt");
    ofstream f_cell("/home/lan/bench2G/result/cell.txt");
    ofstream f_count("/home/lan/bench2G/result/count.txt");
    ofstream f_link_test("/home/lan/bench2G/result/links_test.txt");
    //ofstream f_link_train("/home/lan/bench2G/result/links_train_temp.txt");
    ofstream f_link_train_f("/home/lan/bench2G/result/links_train.txt");
    ofstream f_link_test_neg("/home/lan/bench2G/result/link_test_n.txt");

    string line="";

    while (getline(fin, line)){
        vector<string> gates=parase(line);

        regex pattern("OR|XOR|AND|NAND|XNOR|NOR|MUX|or|xor|and|nand|xnor|nor|mux|BUF|NOT|buf|not");
        smatch result;
        string::const_iterator iter_begin = line.cbegin();
        string::const_iterator iter_end = line.cend();
        if (regex_search(iter_begin, iter_end, result, pattern)){
            string function=result[0];     //获取门的类型
            for(auto& gate:gates){
                if(hs.count(gate)==0){
                    hs[gate]=ID;
                    f_count<<ID<<endl;
                    f_cell<<ID<<" assign for output "<<gate<<endl;
                    f_feat<<featsMap[function]<<endl;
                    ++ID;
                }
            }
            regex pattern_2("keyinput");
            smatch result_2;
            string::const_iterator iter_begin_2 = line.cbegin();
            string::const_iterator iter_end_2 = line.cend();
            if((function=="MUX"||function=="mux")&&regex_search(iter_begin_2, iter_end_2, result_2, pattern_2)){      //含有keyinputs的MUX门区分原始的MUX
                //获取key
                int pos=line.find("keyinput");
                pos=pos+8;
                int num=0;
                while('0'<=line[pos]&&line[pos]<='9'){
                    num=num*10;
                    num+=line[pos]-'0';
                    ++pos;
                }

                char keybit=keyInputBits[num];
                if(keybit=='0'){
                    f_link_test<<hs[gates[1]]<<" "<<hs[gates[0]]<<endl;
                    f_link_test_neg<<hs[gates[2]]<<" "<<hs[gates[0]]<<endl;
                }else{
                    f_link_test_neg<<hs[gates[1]]<<" "<<hs[gates[0]]<<endl;
                    f_link_test<<hs[gates[2]]<<" "<<hs[gates[0]]<<endl;
                }

                Graph[hs[gates[0]]][hs[gates[1]]]=1;
                Graph[hs[gates[0]]][hs[gates[2]]]=1;

            }else{
                int beg=hs[gates[0]];
                for(int i=1;i<gates.size();++i){
                    int end=hs[gates[i]];
                    f_link_train_f<<end<<" "<<beg<<endl;
                    Graph[beg][end]=1;
                }
            }

        }else{
            // regex pattern_3("input|INPUT");
            // smatch result_3;
            // string::const_iterator iter_begin_3 = line.cbegin();
            // string::const_iterator iter_end_3 = line.cend();
            // if(regex_search(iter_begin_3, iter_end_3, result_3, pattern_3)){
            //     if(hs.count(gates[0])==0){
            //         hs[gates[0]]=ID;
            //         ++ID;
            //     }
            //     InputGates.push_back(hs[gates[0]]);
            // }
            int a=0;
        }
    }
}