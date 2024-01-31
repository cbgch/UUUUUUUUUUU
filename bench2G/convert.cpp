//给电路的输入和输出端添加上MUX
//是论文"Discerning Limitations of GNN-based Attacks on Logic Locking"中方法一的实现
#include<bits/stdc++.h>

using namespace std;

int numIn=0,numOut=0;
set<string> InSet;
set<string> OutSet;

map<int,string> InArr;
map<int,string> OutArr;
map<int,string> realIn;
map<int,string> realOut;

map<string,int> InMap;
map<string,int> OutMap;
// map<int,string> InMap;
// map<int,string> OutMap;

// map<string,vector<int>> features;

string getGate(string line){
    int beg=line.find("(");
    string gates="";
    ++beg;
    while(line[beg]!=')'){
        gates.push_back(line[beg]);
        ++beg;
    }
    return gates;
}

int main(){
    ifstream f("/home/lan/bench2G/c7552.bench");
    ifstream fin("/home/lan/bench2G/c7552.bench");
    ofstream fout("/home/lan/bench2G/c7552_locked.bench");
    ofstream keysOut("/home/lan/bench2G/keyBits.txt");
    

    //首先统计文件里有多少个INPUT和OUTPUT门，确定要插入的MUX的数量，然后生成对应长度的keys
    string line;
    int total=0;
    while (getline(f, line)) {
        //匹配input和ouput
        int index = line.find("INPUT");
        if(index < line.length()){
            string gates=getGate(line);
            //cout<<gates<<endl;
            if(InSet.count(gates)==0){
                InSet.insert(gates);
                InArr[total]=gates;
                realIn[total]="R"+gates;
                InMap[gates]=total;

                fout<<"INPUT(R"<<gates<<")"<<endl;
                fout<<"INPUT(keyinput"<<total<<")"<<endl;
            }
            ++total;
        }

        index=line.find("OUTPUT");
        if(index < line.length()){
            string gates=getGate(line);
            //cout<<gates<<endl;
            if(OutSet.count(gates)==0){
                OutSet.insert(gates);
                OutArr[total]=gates;
                realOut[total]="R"+gates;
                OutMap[gates]=total;

                fout<<"OUTPUT(R"<<gates<<")"<<endl;
                fout<<"INPUT(keyinput"<<total<<")"<<endl;
            }
            ++total;
        }
    }
    f.close();

    //根据获得的总数生成对应长度的key
    cout<<total<<endl;
    string keyBits="";
    for(int i=0;i<total;i++){
        if(rand()%2==0){
            keyBits.push_back('0');
        }else {
            keyBits.push_back('1');
        }
    }
    keysOut<<keyBits<<endl;

    //打开文件将里面的所有的INPUT(G)的G给读取出来，然后将他们作为一个MUX的输出，MUX的输入端有三个，分别是keysinput, realinput和fakeinput(根据keysinput确定:0在前面，1在后面),注意真假应该不一样
    while (getline(fin, line)) {
        //匹配input和ouput
        int index = line.find("INPUT");
        if(index < line.length()){
            string gates=getGate(line);
            int pos=InMap[gates];       //pos是在IN和OUT总体中的Pos
            int otherPos=pos;
            while(1){
                otherPos=rand()%total;
                if(otherPos!=pos&&InArr.count(otherPos)==1){
                    break;
                }
            }
            if(keyBits[pos]=='0'){
                fout<<gates<<" = MUX(keyinput"<<pos<<", "<<realIn[pos]<<", "<<realIn[otherPos]<<")"<<endl;
            }else{
                fout<<gates<<" = MUX(keyinput"<<pos<<", "<<realIn[otherPos]<<", "<<realIn[pos]<<")"<<endl;
            }
        }else {
            index=line.find("OUTPUT");
            if(index < line.length()){
                string gates=getGate(line);
                int pos=OutMap[gates];
                int otherPos=pos;
                while(1){
                    otherPos=rand()%total;
                    if(otherPos!=pos&&OutArr.count(otherPos)==1){
                        break;
                    }
                }
                if(keyBits[pos]=='0'){
                    fout<<realOut[pos]<<" = MUX(keyinput"<<pos<<", "<<OutArr[pos]<<", "<<OutArr[otherPos]<<")"<<endl;
                }else{
                    fout<<realOut[pos]<<" = MUX(keyinput"<<pos<<", "<<OutArr[otherPos]<<", "<<OutArr[pos]<<")"<<endl;
                }

            }else{
                fout<<line<<endl;
            }
        }
    }
    f.close();
}