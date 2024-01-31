#include <bits/stdc++.h>
using namespace std;

int countKey=1;

vector<string> Stringsplit(string str){  //按空格划分
    vector<string> ret;
    string temp="";
    int n=str.size();
    for(int i=0;i<n;i++){
        if(str[i]==' '){
            if(!temp.empty()){
                ret.push_back(temp);
                temp="";
            }
        }else{
            temp.push_back(str[i]);
        }
    }
    if(!temp.empty()){
        ret.push_back(temp);
    }
    return ret;
}

void trim(string& s)
{
    while(s.back()==' '||s.back()=='\t'||s.back()=='\n') s.pop_back();
    while(s[0]==' '||s[0]=='\t'||s[0]=='\n') s=s.substr(1);
}

string getContent(string str){   //获取字符串中括号的内容
    string ret="";
    int pos=str.find("(");
    ++pos;
    if(pos==string::npos)return "";
    while(str[pos]!=')'&&str[pos]!=' '){
        ret.push_back(str[pos]);
        ++pos;
    }
    return ret;
}

int main(){
    ifstream f("/home/lan/bench2G/c1355_1.v");
    ofstream fout("/home/lan/bench2G/c1355_1_AddXor.v");

    string line="";
    while(getline(f,line)){
        //XOR2_X1 U319 ( .A(G218gat), .B(n287), .Z(G1355gat) );

        //XOR2_X1 U319 ( . )
        if(line.find("XOR")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            //arr[0]="XOR";
            string gateType=arr[0];
            string gateName=arr[1];
            string modifiedName=gateName.push_back('_');
            string wire=getContent(arr[3]);


            for(int i=3;i<n;i++){
                string ts=getContent(arr[i]);
                if(!ts.empty())arr[i]=ts;
            }

            for(int i=0;i<n;i++){
                trim(arr[i]);
            }

            fout<<arr[0]<<" "<<arr[1]<<arr[2]<<arr[3];
            for(int i=4;i<n;i++){
                if(arr[i][0]!=')')
                    fout<<","<<arr[i];
            }
            fout<<");"<<endl;
        }else if(line.find("XNOR")!=string::npos){

        }else{
            fout<<line<<endl;
        }
    }
}