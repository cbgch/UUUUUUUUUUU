#include<bits/stdc++.h>
using namespace std;

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

vector<string>  spiltByD(string str){
    int n=str.size();
    vector<string> res;
    string temp="";
    for(int i=0;i<n;i++){
        if(str[i]==','){
            res.push_back(temp);
            temp="";
        }else if(str[i]!=' '){
            temp.push_back(str[i]);
        }
    }
    if(!temp.empty()){
        res.push_back(temp);
    }
    return res;
}

string getLineName(string str){
    int n=str.size();
    trim(str);
    int count=0;
    int posBeg,posEnd;
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            if(count==0){
                posBeg=i;
            }else{
                posEnd=i;
            }
            ++count;
        }
        if(count==2){
            break;
        }
    }
    return str.substr(posBeg+1,posEnd-posBeg-1);
}

class Node{
    public:
        int val;
    public:
    Node(){}
};


int matr[1000][1000];

int main(){
    //string line = " G99gat  = MUX(keyinput143212sad, RG64gat, RG99gat)";
    //string line = "    input(     keyinput14, RG64gat, RG99gat)     ";
    //vector<string> outputs=parase(trim(line));
    // for(auto& str:outputs){
    //     cout<<str<<endl;
    // }





    // int pos=line.find("keyinput");
    // pos=pos+8;
    // int num=0;
    // while('0'<=line[pos]&&line[pos]<='9'){
    //     num=num*10;
    //     num+=line[pos]-'0';
    //     ++pos;
    // }
    // cout<<num<<endl;

    



    // memset(matr,0,sizeof(matr));
    // for(int i=0;i<1000;i++){
    //     for(int j=0;j<1000;j++){
    //         cout<<matr[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }


    //正则表达式测试
    // regex pattern("mux|and");	/*匹配一个到无穷个数字*/
	// string s = "G99gat = mux(keyinput14, RG64gat, RG99gat)";
	// smatch result;
	// string::const_iterator iter_begin = s.cbegin();
	// string::const_iterator iter_end = s.cend();
	// if (regex_search(iter_begin, iter_end, result, pattern))
	// {
	// 	cout << "查找成功：" << result[0] << endl;
    //     string str=result[0];
    //     cout<<"str:"<<str<<endl;
	// 	// cout << "查找结果子串的在源串中的迭代器位置" << *result[0].first << endl;
	// 	// cout << "查找结果子串的在源串后面的位置" << *result[0].second << endl;
	// 	// iter_begin = result[0].second;	//更新迭代器位置
	// }else{
    //     cout<<"查找失败"<<endl;
    // }
	// return 0;


    // queue<int> q;
    // for(int i=0;i<9;i++){
    //     q.push(i);
    // }
    // string str1="a";
    // string str2="b";
    // string str3="c";
    // string name=str1+str2+str3;
    // cout<<name<<endl;

    // string rep = "G123muxsadas";
    // string buf = "G692gat = nand(G612gat, G669gat)";
    // string fnd = "G669gat";
    // buf = buf.replace(buf.find(fnd), fnd.length(), rep);
    // cout<<buf<<endl;
    string str="101111001101011000001011000111100011101011110100101010010001110101011101010100101000001101000010000110001110100010011101011111111110110101100101110001010101011110001010000010111110011011010111110011010011100000001110010101010011001000111001001100001011100100000100000100000110011110100111101110010000000001101010001";
    cout<<str.size()<<endl;
    str="111010010011001101111100111000100010000110010001001011101010011111100100100000011011001111011001101001100011111101000101010001010010010010110011010100001000010110110110000110001101001010101001110100101000010001010110100101010011011010011011011010001001111100100000010001101011011000101101011001100110111010011011100101000001001111001011111101100101000001111011001110101111101001010001010111000001011011100111000001110010101111011011111111010110110110001001001100101110100101100010011011011001101111100111000011001010001011100110110000000111011111011";
    cout<<str.size()<<endl;

    vector<string> arr;
    str=" input  G22, G23, G24, G25, G26, G27, G28, G29, G3, G30, G31, G32, G33, G34,";
    arr=spiltByD(str);
    for(auto& a:arr){
        cout<<a<<endl;
    }

    cout<<endl<<endl<<endl<<endl<<endl;

    // string line="nsaidu input             4545  ";
    // if((line.find("input")!=string::npos)||line.find("INPUT")!=string::npos){
    //     //state=1;
    //     int pos=line.find("input");
    //     if(pos<line.length()){
    //         pos+=5;
    //         line=line.substr(pos);
    //     }else{
    //         pos=line.find("INPUT");
    //         pos+=5;
    //         line=line.substr(pos);
    //     }
    // }
    // cout<<line<<"&&"<<endl;

        // string line="NOR4_X1 U1193 ( .A1(n1712), .A2(n1713), .A3(n1714), .A4(n1599), .ZN(n1711));";
        // regex pattern("OR|XOR|AND|NAND|XNOR|NOR|MUX|INV|or|xor|and|nand|xnor|nor|mux|BUF|NOT|buf|not");
        // smatch result;
        // string::const_iterator iter_begin = line.cbegin();
        // string::const_iterator iter_end = line.cend();
        // if (regex_search(iter_begin, iter_end, result, pattern)){
        //     string function=result[0];
        //     cout<<function<<endl;
        // }else{
        //     cout<<"不匹配"<<endl;
        // }

        // string line="NOR4_X1 U1193 ( .A1(n1712), .A2(n1713), .A3(n1714), .A4(n1599), .ZN(n1711));";
        // cout<<getLineName(line)<<"a"<<endl;


        // vector<string> arrs={"a","b","c"};
        // vector<string> ta={arrs.back()};
        // arrs.pop_back();
        // for(auto a:arrs){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // cout<<ta[0]<<endl;

        // string line="asdawmodule0000000000 c3542( G1, G10, G11, G12, G13, G14, G15, G16, G17, G18, G19, G2, G20,";
        // int ind=line.find("module");
        // cout<<ind<<endl;
        // if(ind!=string::npos){
        //     ind+=6;
        //     line=line.substr(ind);
        //     line = trim(line);
        //     ind=0;
        //     while(line[ind]!='('&&line[ind]!=' '){
        //         ++ind;
        //     }
        //     string moduleName=line.substr(0,ind);
        //     cout<<ind<<endl;
        //     cout<<moduleName<<"H"<<endl;
        // }
        vector<Node> arrs;
        for(int i=0;i<10;i++){
            Node n;
            n.val=i;
            arrs.push_back(n);
        }
        for(auto&arr:arrs){
           ++arr.val;
        }
        for(auto arr:arrs){
            cout<<arr.val<<" ";
        }
        cout<<endl;
}
