#include<bits/stdc++.h>
using namespace std;

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

int main(){
    string str="and AND2_165 (N718, N432, N650);";
    int pos=str.find("(");
    string sub=str.substr(pos+1,str.size()-pos-3);
    cout<<"sub: "<<sub<<endl;
    vector<string> arr=spiltByD(sub);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}