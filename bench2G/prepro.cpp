#include<bits/stdc++.h>
using namespace std;

vector<string> Stringsplit(string str)
{
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
    ifstream fin("/home/lan/bench2G/c3540_1.v");
    ofstream fout("/home/lan/bench2G/c3540_pro.v");

    string line="";
    while(getline(fin,line)){
        if(line.find("NAND")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="NAND";
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
        }else if(line.find("NOR")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="NOR";
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
        }else if(line.find("NXOR")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="NXOR";
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
        }else if(line.find("AND")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="AND";
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
        }else if(line.find("XOR")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="XOR";
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
        }else if(line.find("OR")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="OR";
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
        }else if(line.find("NOT")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="NOT";
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
        }else if(line.find("BUF")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="BUF";
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
        }else if(line.find("INV")!=string::npos){
            trim(line);
            vector<string> arr=Stringsplit(line);
            int n=arr.size();
            arr[0]="INV";
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
        }else{
            fout<<line<<endl;
        }
    }  
}
