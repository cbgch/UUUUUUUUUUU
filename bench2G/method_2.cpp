//将benchmark格式的电路转换为图结构,并选择在同级的电路中加上MUX门实现锁定
//是论文Discerning Limitations of GNN-based Attacks on Logic Locking中方法二是实现
//转成的图是用来做链路预测的，参考MUXlink的实现方法
#include<bits/stdc++.h>
using namespace std;

#define LEVEL 2         //选择在电路的第几层添加MUX混淆
#define SIZE 5000      //构造的有向图的大小

map<string,string> featsMap;
//vector<int> InputGates;   //存储input门，方便确定门在图中的深度
set<string> InputGates;   //存储input门，方便确定门在图中的深度
vector<int> count;      //gate对应的id编号
vector<string> function;     //buf,MUX,and....., 包括input但没有output

static int ID=0;
//int sum=0;      //统计总共有多少output

int Graph[SIZE][SIZE];   //图的邻接矩阵, 根据电路规模大小设置图的大小  0->无边 1->train边 2->test边 3->test_n边

queue<int> levelQ;   //存储同一层的节点的队列，用于BFS
set<int> added;      //防止重复向队列中加入

static int countMUX=0;   //统计往电路中加了多少个MUX,从而确定keybits的长度

map<string,int> hs;  //存放gate名字到id的映射
map<int,string> hs_2;  //id到gate的映射

vector<int> begs;    //保存level层的gate的id

string keyInputBits="";  //!根据添加的MUX的数量来确定keybits的长度

vector<string> fileInfo;

int keySize=0;

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

    ifstream fin("/home/lan/bench2G/c7552.bench");         //读取要加密的文件
    ofstream f_feat("/home/lan/bench2G/method2/feat.txt");
    ofstream f_cell("/home/lan/bench2G/method2/cell.txt");
    ofstream f_count("/home/lan/bench2G/method2/count.txt");
    ofstream f_link_test("/home/lan/bench2G/method2/links_test.txt");
    //ofstream f_link_train("/home/lan/bench2G/result/links_train_temp.txt");
    ofstream f_link_train_f("/home/lan/bench2G/method2/links_train.txt");
    ofstream f_link_test_neg("/home/lan/bench2G/method2/link_test_n.txt");

    ofstream keyOut("/home/lan/bench2G/method2/keyBits.txt");

    ofstream locked("/home/lan/bench2G/method2/c7552_locked.txt");   //生成锁定的电路

    string line="";

    /****************************************************************
        ->实现思路：
            (1) 先将原始电路转化为图，保存到Graph中
            (2) 对图从input节点开始进行BFS，遍历到对应LEVEL时在下一级添加MUX混淆
            (3) 如果一个门的所有输入端都是INPUT，则它被认为是属于level=1
    
    ****************************************************************/

    //首先获取所有的INPUT
    ifstream f_input("/home/lan/bench2G/c7552.bench");
    while(getline(f_input,line)){
        if(line.size()>2)fileInfo.push_back(line);
        vector<string> gates=parase(line);

        regex pattern("INPUT|input");
        smatch result;
        string::const_iterator iter_begin = line.cbegin();
        string::const_iterator iter_end = line.cend();

        if (regex_search(iter_begin, iter_end, result, pattern)){
            InputGates.insert(gates[0]);
        }
    }
    f_input.close();


    while (getline(fin, line)){
        vector<string> gates=parase(line);

        regex pattern("OR|XOR|AND|NAND|XNOR|NOR|MUX|or|xor|and|nand|xnor|nor|mux|BUF|NOT|buf|not");
        smatch result;
        string::const_iterator iter_begin = line.cbegin();
        string::const_iterator iter_end = line.cend();
        if (regex_search(iter_begin, iter_end, result, pattern)){
            string function=result[0];     //获取门的类型
            for(auto& gate:gates){
                if(hs.count(gate)==0&&InputGates.count(gate)==0){        //不将INPUT端添加到图中
                    hs[gate]=ID;
                    hs_2[ID]=gate;
                    f_count<<ID<<endl;
                    f_cell<<ID<<" assign for output "<<gate<<endl;
                    f_feat<<featsMap[function]<<endl;
                    ++ID;
                }
            }
            int end=hs[gates[0]];
            bool one=true;
            for(int i=1;i<gates.size();i++){
                if(InputGates.count(gates[i])==0){
                    one=false;
                    int beg=hs[gates[i]];
                    Graph[beg][end]=1;
                }
            }
            if(one){
                levelQ.push(end);
                added.insert(end);
            }
        }
    }



    //向图中添加MUX混淆
    int cur=1;
    while(levelQ.size()>0){
        if(cur==LEVEL){
            int n=levelQ.size();
            
            // //生成keybits
            // for(int i=0;i<n;i++){
            //     if(rand()%2==0){
            //         keyInputBits.push_back('0');
            //     }else{
            //         keyInputBits.push_back('1');
            //     }
            // }
            // cout<<keyInputBits<<"  "<<keyInputBits.size()<<endl;

            //先保存为数组
            for(int i=0;i<n;i++){
                int beg=levelQ.front();
                levelQ.pop();
                begs.push_back(beg);
            }

            //添加MUX
            for(int i=0;i<n;i++){
                for(int j=0;j<SIZE;j++){
                    if((Graph[begs[i]][j]==1)&&(added.count(j)==0)){    //只想第LEVEL和LEVEL+1层之间加

                        if(rand()%2==0){
                            keyInputBits.push_back('0');
                        }else{
                            keyInputBits.push_back('1');
                        }

                        //MUX输出端的名字如：G123mux
                        string str1="G";
                        string str2=to_string(ID);
                        string str3="mux";
                        string name=str1+str2+str3;

                        int beg=begs[i];
                        int k=ID;
                        f_count<<ID<<endl;
                        f_cell<<ID<<" assign for output "<<name<<endl;
                        f_feat<<featsMap["MUX"]<<endl;

                        hs[name]=ID;
                        hs_2[ID]=name;
                        int other=i;
                        while(i==other){
                            other=rand()%n;
                        }

                        other=begs[other];          //取出来的是同一级另一个门的id


                        Graph[beg][j]=0;   //k代表的就是新插入的MUX
                        Graph[beg][k]=2;
                        cout<<beg<<" "<<k<<endl;
                        Graph[other][k]=3;
                        Graph[k][j]=1;

                        //G1gat = MUX(keyinput0, RG120gat, RG1gat)
                        string equal=" = ";
                        string muxG="MUX";
                        string left="(";
                        string right=")";
                        string spiltC=", ";
                        string realOut=hs_2[j];
                        string muxOut=name;  //hs_2[k];
                        string otherIn=hs_2[other];
                        string realIn=hs_2[beg];
                        string info="";
                        string keyStr="keyinput";
                        keyStr=keyStr+to_string(i);
                        //先修改output端
                        int len=fileInfo.size();

                        for(int k=0;k<len;k++){
                            //cout<<fileInfo[k]<<endl;
                            vector<string> gates=parase(fileInfo[k]);
                            // for(auto& gate:gates){
                            //     cout<<gate<<" ";
                            // }
                            // cout<<endl;
                            if(gates.size()==1){
                                continue;
                            }
                            if(gates[0]==realOut){
                                fileInfo[k] = fileInfo[k].replace(fileInfo[k].find(realIn), realIn.length(), muxOut);
                            }
                        }
                        
                        //再添加MUX
                        if(keyInputBits[i]=='0'){
                            info=muxOut+equal+muxG+left+keyStr+spiltC+realIn+spiltC+otherIn+right;
                            fileInfo.push_back(info);
                            cout<<"mark0"<<endl;
                        }else{
                            info=muxOut+equal+muxG+left+keyStr+spiltC+otherIn+spiltC+realIn+right; 
                            fileInfo.push_back(info);
                            cout<<"mark1"<<endl;
                        }
                        ++ID;           
                    }
                }   
            }
            break;
        }else{
            int lens=levelQ.size();
            for(int i=0;i<lens;i++){
                int beg=levelQ.front();
                levelQ.pop();
                for(int j=0;j<SIZE;j++){
                    if(Graph[i][j]!=0&&added.count(j)==0){
                        levelQ.push(j);
                        added.insert(j);
                    }
                }
            }
        }

        ++cur;
    }


    for(auto& info:fileInfo){
        locked<<info<<endl;
    }
    //写入边文件 1->train  2->test  3->test_n
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(Graph[i][j]==1){
                f_link_train_f<<i<<" "<<j<<endl;
            }
            if(Graph[i][j]==2){
                f_link_test<<i<<" "<<j<<endl;
            }
            if(Graph[i][j]==3){
                f_link_test_neg<<i<<" "<<j<<endl;
            }
        }
    }

    //cout<<"G: "<<Graph[102][624]<<endl;

    keyOut<<keyInputBits<<endl;   //保存keys
    keyOut.close();
}