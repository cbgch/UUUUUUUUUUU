//锁定电路中的xor和nxor门
#include<bits/stdc++.h>
using namespace std;

class gateNode{
    public:
        string name;
 		vector<string> inputs;
 		int count;   
 		string bool_func;                       //=> $args->{bool_func}, # {OR, AND etc}
 		vector<string> fwdgates;                //=> $args->{fwdgates},   #存放当前门对象的输出端连接的所有节点的列表(例如PI，KI，AND，OR等)
 		vector<string> fwdgates_inst;           //=> $args->{fwdgates_inst}, #存放当前门对象的输出端连接的所有节点的列表(如 G1，KEYINPUT1等)
 		//vector<string> output;                  // => $args->{output},    #存n1019
		//processed => $args->{processed}, # 存module id即存储模块 or key0 key1，含有keyinput的门的processed是key0 or key1，其他门存module id
 		vector<string> outputs;                 // => $args->{outputs},   
 		vector<string> fedbygates;              //=> $args->{fedbygates},     #存放当前门对象的输入端连接的其他所有节点的列表(例如PI，KI，AND，OR等)
 		vector<string> fedbygates_inst;         //=> $args->{fedbygates_inst},  #存放当前门对象的输入端连接的其他所有节点的列表(如 G1，KEYINPUT1等)

        gateNode(){}
};

vector<gateNode> Nodes;
set<string> inputsG;
set<string> outputG;
string keyBit="";
//map<string,string> outport2Gate;   //存储门对应的输出端口

string moduleName="";    //存储模块的名字

static int countG=0;  //为门编号

void trim(string& s)
{
    while(s.back()==' '||s.back()=='\t'||s.back()=='\n') s.pop_back();
    while(s[0]==' '||s[0]=='\t'||s[0]=='\n') s=s.substr(1);
}


bool spiltD(string str,int sta){  //返回true表示遇到了分号，需要结束了  该函数的功能是获取n123**之类的输入端口
    trim(str);
    int n=str.size();
    string port="";
    bool ret=false;
    for(auto& ch:str){
        if(('0'<=ch&&ch<='9')||('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')){
            port.push_back(ch);
        }else{
            if(!port.empty()){
                if(sta==1){
                    inputsG.insert(port);
                }else{
                    outputG.insert(port);
                }
                port="";
            }
            if(ch==';'){
                ret=true;
            }
        }
    }
    if(!port.empty()){
        if(sta==1){
            inputsG.insert(port);
        }else{
            outputG.insert(port);
        }
    }
    return ret;
}

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
//NAND4_X1 U1192 ( .A1(n1709), .A2(n1710), .A3(n1602), .A4(n1711), .ZN(n1708));
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

void processFun(string line, string func){
    trim(line);
    gateNode gn;

    vector<string> arr=Stringsplit(line);
    int n=arr.size();
    //arr[0] --> NAND; arr[1] --> U1192; arr[2] -->( ;arr[3] -->
    gn.bool_func=func;
    for(int i=3;i<n;i++){
        string ts=getContent(arr[i]);
        if(!ts.empty())arr[i]=ts;
    }

    for(int i=0;i<n;i++){
        trim(arr[i]);
    }

    //fout<<arr[0]<<" "<<arr[1]<<arr[2]<<arr[3];
    gn.name=arr[1];
    vector<string> gates;
    for(int i=3;i<n;i++){
        if(arr[i][0]!=')')
            gates.push_back(arr[i]);
    }
    //fout<<");"<<endl;
    //!!!!!!!因为这里处理的逻辑门都是单输出的，因此直接确定gates的最后一个为output，如果有多输出的逻辑门则需要修改
    gn.outputs={gates.back()};
    gates.pop_back();
    gn.inputs=gates;
    gn.count=countG;
    Nodes.push_back(gn);
    //outport2Gate[gn.name]=gn.outputs[0];
    
}

/*
    实现思路：
        (1) 先读取input和output门
        (2) 然后构造图    
*/
int main(){
    ifstream f("/home/lan/bench2G/c1355_1.v");
    ifstream fin("/home/lan/bench2G/c1355_1.v");
    ofstream fout("/home/lan/bench2G/c1355_1_xorLocked.v");

    string line="";
    int state=0;  //0-->1-->2-->3-->4: 1代表进入input阶段，3代表进入output阶段   !!需要根据文件的input和output位置进行调整
    while(getline(f,line)){
        if(state==4){
            break;
        }
        if(state==0){
            int ind=line.find("module");
            if(ind<line.length()){
                ind+=6;
                line=line.substr(ind);
                trim(line);
                ind=0;
                while(line[ind]!='('&&line[ind]!=' '){
                    ++ind;
                }
                moduleName=line.substr(0,ind);   //获取模块名字
            }


            if((line.find("input")!=string::npos)||line.find("INPUT")!=string::npos){
                state=1;
                int pos=line.find("input");
                if(pos<line.length()){
                    pos+=5;
                    line=line.substr(pos);
                }else{
                    pos=line.find("INPUT");
                    pos+=5;
                    line=line.substr(pos);
                }
            }
        }
        if(state==1){
            if(spiltD(line,1)){
                state=2;   //2代表input阶段结束但是output阶段还没开始
            }
        }
        if(state==2){
            if((line.find("output")!=string::npos)||line.find("OUTPUT")!=string::npos){
                state=3;
                int pos=line.find("output");
                if(pos<line.length()){
                    pos+=6;
                    line=line.substr(pos);
                }else{
                    pos=line.find("OUTPUT");
                    pos+=6;
                    line=line.substr(pos);
                }
            }
        }
        if(state==3){
            if(spiltD(line,3)){
                state=4;   //2代表input阶段结束但是output阶段还没开始
            }
        }
    }

    //构建图结构
    //1.先获取全部的图节点
    while(getline(f,line)){
        regex pattern("OR|XOR|AND|NAND|XNOR|NOR|MUX|INV|BUF|NOT");
        smatch result;
        string::const_iterator iter_begin = line.cbegin();
        string::const_iterator iter_end = line.cend();
        if (regex_search(iter_begin, iter_end, result, pattern)){
            //NAND4_X1 U1192 ( .A1(n1709), .A2(n1710), .A3(n1602), .A4(n1711), .ZN(n1708));
            if(line.find("NAND")!=string::npos){
                processFun(line,"NAND");
            }else if(line.find("XNOR")!=string::npos){
                processFun(line,"XNOR");
            }else if(line.find("NOR")!=string::npos){
                processFun(line,"NOR");
            }else if(line.find("AND")!=string::npos){
                processFun(line,"AND");
            }else if(line.find("XOR")!=string::npos){
                processFun(line,"XOR");
            }else if(line.find("OR")!=string::npos){
                processFun(line,"OR");
            }else if(line.find("NOT")!=string::npos){
                processFun(line,"NOT");
            }else if(line.find("BUF")!=string::npos){
                processFun(line,"BUF");
            }else if(line.find("INV")!=string::npos){
                processFun(line,"INV");
            }
            
            ++countG;
        }
    }
    //cout<<outputG.size()<<endl;

    //2.处理PO 和 PI
    int n=Nodes.size();
    for(int i=0;i<n;i++){
        // vector<string> fwdArr;
        // vector<string> fwdArrIn;
        int len=Nodes[i].outputs.size();
        for(int j=0;j<len;j++){
            if(outputG.count(Nodes[i].outputs[j])){
                Nodes[i].fwdgates.push_back("PO");
                Nodes[i].fwdgates_inst.push_back(Nodes[i].outputs[j]);
            }
        }
        len=Nodes[i].inputs.size();
        for(int j=0;j<len;j++){
            if(inputsG.count(Nodes[i].inputs[j])){
                Nodes[i].fedbygates.push_back("PI");
                Nodes[i].fedbygates_inst.push_back(Nodes[i].inputs[j]);
            }
        }
    }

    //3.建立边的连接
    n=Nodes.size();
    for(int i=0;i<n;i++){
        gateNode& inner=Nodes[i];
        for(int j=0;j<n;j++){
            gateNode& outer=Nodes[j];
            for(int x=0;x<outer.outputs.size();x++){
                for(int y=0;y<inner.inputs.size();y++){
                    if(outer.outputs[x]==inner.inputs[y]){
                        inner.fedbygates.push_back(outer.bool_func);
                        inner.fedbygates_inst.push_back(outer.name);
                        outer.fwdgates.push_back(inner.bool_func);
                        outer.fedbygates_inst.push_back(inner.name);
                    }
                }
            }
        }
    }

    //在构建的图中根据自己需要添加各种锁定
    //这里是锁定原始电路中的异或门,即在异或门上再添加异或门进行锁定
    //keybit为奇数则插入xnor，偶数插入xor

    int keyCount=1;  //设置key为10101010******
    int xorCount=1000;
    int wireCount=1000;
    string X="X";
    string w="w";
    string keyName="KEYINPUT";
    n=Nodes.size();
    int testN = 0;
    for(auto& obj:Nodes){
        if(obj.bool_func=="XOR"||obj.bool_func=="XNOR"){
            int len=obj.fedbygates.size();
            for(int j=0;j<len;j++){
                cout<<testN++<<endl;
                if(obj.fedbygates[j]=="PI"){
                    gateNode lockNode;
                    // string name;
                    // vector<string> inputs;
                    // int count;   
                    // string bool_func;                       //=> $args->{bool_func}, # {OR, AND etc}
                    // vector<string> fwdgates;                //=> $args->{fwdgates},   #存放当前门对象的输出端连接的所有节点的列表(例如PI，KI，AND，OR等)
                    // vector<string> fwdgates_inst;           //=> $args->{fwdgates_inst}, #存放当前门对象的输出端连接的所有节点的列表(如 G1，KEYINPUT1等)
                    // vector<string> outputs;                 // => $args->{outputs},   
                    // vector<string> fedbygates;              //=> $args->{fedbygates},     #存放当前门对象的输入端连接的其他所有节点的列表(例如PI，KI，AND，OR等)
                    // vector<string> fedbygates_inst;         //=> $args->{fedbygates_inst},  #存放当前门对象的输入端连接的其他所有节点的列表(如 G1，KEYINPUT1等)

                    if(keyCount%2==0){    //当前锁定门对应的keyinput为1，所以应该添加同或门
                        lockNode.bool_func="XNOR";
                        keyBit.push_back('0');
                    }else{          //添加异或门
                        lockNode.bool_func="XOR";
                        keyBit.push_back('1');
                    }
                    lockNode.count=countG;
                    lockNode.name=X+to_string(xorCount);

                    string addWire=w+to_string(wireCount);

                    //设置添加的
                    string pin=obj.fedbygates_inst[j];
                    lockNode.inputs.push_back(pin);
                    lockNode.inputs.push_back(keyName+to_string(keyCount-1));
                    lockNode.outputs.push_back(addWire);
                    lockNode.fwdgates.push_back(obj.bool_func);
                    lockNode.fwdgates_inst.push_back(obj.name);
                    lockNode.fedbygates.push_back("PI");
                    lockNode.fedbygates_inst.push_back(pin);
                    lockNode.fedbygates.push_back("KI");
                    lockNode.fedbygates_inst.push_back(keyName+to_string(keyCount-1));
                        
                    //更新obj
                    for(int k=0;k<obj.inputs.size();k++){
                        if(obj.inputs[k]==pin){
                            obj.inputs[k]=addWire;
                            break;
                        }
                    }
                    obj.fedbygates[j]=lockNode.bool_func;
                    obj.fedbygates_inst[j]=lockNode.name;
                    ++keyCount;
                    ++wireCount;
                    ++xorCount;

                    Nodes.push_back(lockNode);
                }else{
                    string oldGateFun=obj.fedbygates[j];
                    string oldGateName=obj.fedbygates_inst[j];

                    int oldObjPos=0;
                    for(int v=0;v<Nodes.size();v++){
                        if(Nodes[v].name==oldGateName){
                            oldObjPos=v;
                            break;
                        }
                    }

                    gateNode lockNode;
                    // string name;
                    // vector<string> inputs;
                    // int count;   
                    // string bool_func;                       //=> $args->{bool_func}, # {OR, AND etc}
                    // vector<string> fwdgates;                //=> $args->{fwdgates},   #存放当前门对象的输出端连接的所有节点的列表(例如PI，KI，AND，OR等)
                    // vector<string> fwdgates_inst;           //=> $args->{fwdgates_inst}, #存放当前门对象的输出端连接的所有节点的列表(如 G1，KEYINPUT1等)
                    // vector<string> outputs;                 // => $args->{outputs},   
                    // vector<string> fedbygates;              //=> $args->{fedbygates},     #存放当前门对象的输入端连接的其他所有节点的列表(例如PI，KI，AND，OR等)
                    // vector<string> fedbygates_inst;         //=> $args->{fedbygates_inst},  #存放当前门对象的输入端连接的其他所有节点的列表(如 G1，KEYINPUT1等)

                    if(keyCount%2==0){    //当前锁定门对应的keyinput为1，所以应该添加同或门
                        lockNode.bool_func="XNOR";
                        keyBit.push_back('0');
                    }else{          //添加异或门
                        lockNode.bool_func="XOR";
                        keyBit.push_back('1');
                    }
                    lockNode.count=countG;
                    lockNode.name=X+to_string(xorCount);
                    string addWire=w+to_string(wireCount);

                    string oldLine=Nodes[oldObjPos].outputs[0];           
      
                    //根据obj的输入端找到对应的输出端口
                    lockNode.inputs.push_back(addWire);
                    lockNode.inputs.push_back(keyName+to_string(keyCount-1));
                    lockNode.outputs.push_back(oldLine);
                    lockNode.fwdgates.push_back(obj.bool_func);
                    lockNode.fwdgates_inst.push_back(obj.name);
                    lockNode.fedbygates.push_back(Nodes[oldObjPos].bool_func);
                    lockNode.fedbygates_inst.push_back(Nodes[oldObjPos].name);
                    lockNode.fedbygates.push_back("KI");
                    lockNode.fedbygates_inst.push_back(keyName+to_string(keyCount-1));

                    for(int k=0;k<Nodes[oldObjPos].fwdgates_inst.size();k++){
                        if(Nodes[oldObjPos].fwdgates_inst[k]==obj.name){
                            Nodes[oldObjPos].fwdgates_inst[k]=lockNode.name;
                            Nodes[oldObjPos].fwdgates[k]=lockNode.bool_func;
                            break;
                        }
                    }
                    Nodes[oldObjPos].outputs[0]=addWire;

                    obj.fedbygates[j]=lockNode.bool_func;
                    obj.fedbygates_inst[j]=lockNode.name;

                    ++keyCount;
                    ++wireCount;
                    ++xorCount;
                    Nodes.push_back(lockNode);
                }
            }
        }
    }




    //将Nodes按照原来netlist的格式写回到一个.v文件中
    //先读取所有的PI和KEYINPUTn存入inputWb，再读取所有的PO存入outputWb
    vector<string> inputWb;
    vector<string> outputWb;
    set<string> inS;
    set<string> outS;  //去重，避免加入重复的
    n=Nodes.size();
    for(int i=0;i<n;i++){
        int len =Nodes[i].fedbygates.size();
        for(int j=0;j<len;j++){
            if(Nodes[i].fedbygates[j]=="PI"||Nodes[i].fedbygates[j]=="KI"){
                if(inS.count(Nodes[i].fedbygates_inst[j])==0){
                    inputWb.push_back(Nodes[i].fedbygates_inst[j]);
                    inS.insert(Nodes[i].fedbygates_inst[j]);
                }
            }
        }
        len=Nodes[i].fwdgates.size();
        for(int j=0;j<len;j++){
            if(Nodes[i].fwdgates[j]=="PO"){
                if(outS.count(Nodes[i].fwdgates_inst[j])==0){
                    outputWb.push_back(Nodes[i].fwdgates_inst[j]);
                    outS.insert(Nodes[i].fwdgates_inst[j]);
                }
            }
        }
    }

    fout<<"module "<<moduleName<<" ( ";
    int countLine=1;
    for(int i=0;i<inputWb.size();i++){
        if(countLine%15==0){
            fout<<endl;
            countLine=1;
        }
        fout<<inputWb[i]<<",";
        ++countLine;
    }
    for(int i=0;i<outputWb.size()-1;i++){
        if(countLine%15==0){
            fout<<endl;
            countLine=1;
        }
        fout<<outputWb[i]<<",";
        ++countLine;
    }
    fout<<outputWb.back()<<" );"<<endl;
    fout<<"input";
    countLine==1;
    for(int i=0;i<inputWb.size()-1;i++){
        if(countLine%15==0){
            fout<<endl;
            countLine=1;
        }
        fout<<" "<<inputWb[i]<<",";
        ++countLine;
    }
    fout<<" "<<inputWb.back()<<";"<<endl;

    fout<<"output";
    countLine=1;
    for(int i=0;i<outputWb.size()-1;i++){
        if(countLine%15==0){
            fout<<endl;
            countLine=1;
        }
        fout<<" "<<outputWb[i]<<",";
        ++countLine;
    }
    fout<<" "<<outputWb.back()<<";"<<endl;

    /*
        INV_X1 U1270 ( .A(n1748), .ZN(n1744) );
        XNOR2_X1 U1271 ( .A(n1797), .B(n1798), .ZN(n1603) );
        NOR2_X1 U1272 ( .A1(n1799), .A2(n1748), .ZN(n1798) );
    */
    for(auto obj:Nodes){
        fout<<obj.bool_func<<"_X1 "<<obj.name<<" (";
        int n=obj.inputs.size();
        for(int i=0;i<n;i++){
            fout<<" .A"<<i+1<<"("<<obj.inputs[i]<<"),";
        }
        fout<<" .ZN("<<obj.outputs[0]<<") );"<<endl;
    }
    cout<<keyBit<<endl;
    fout.close();
}