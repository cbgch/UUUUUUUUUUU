#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void trim(string& s)
{
    while(s.back()==' '||s.back()=='\t'||s.back()=='\n') s.pop_back();
    while(s[0]==' '||s[0]=='\t'||s[0]=='\n') s=s.substr(1);
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

string getSub(string str){
    int n=str.size();
    if(str[n-2]!=')'){
        return "";
    }
    trim(str);
    int pos=str.find("(");
    if(pos==string::npos){
        return "";
    }
    string sub=str.substr(pos+1,str.size()-pos-3);
    return sub;
}

int main(int argc,char** argv)//main.exe btb
{
    string file_name="c3540_pro";
    string cmd="";

    vector<string> input,output,logic;
    vector<string> andG, orG, notG, xorG,nandG,norG,nxorG,bufG,invG;

    cmd=file_name+".v";
    fstream f1(cmd.c_str(),ios::in);

    while(getline(f1,cmd))
    {
        if(cmd.find("input")!=string::npos) 
        {
            string tmp=cmd;
            trim(tmp);
            while(cmd.find(";")==string::npos) 
            {
                getline(f1,cmd);
                trim(cmd);
                tmp+=cmd;
            }
            input.emplace_back(tmp.substr(tmp.find("input")+5));
        }
        else if(cmd.find("output")!=string::npos) 
        {
            trim(cmd);
            string tmp=cmd;
            while(cmd.find(";")==string::npos) 
            {
                getline(f1,cmd);
                trim(cmd);
                tmp+=cmd;
            }
            output.emplace_back(tmp.substr(tmp.find("output")+6));
        }
        else if(cmd.find("assign")!=string::npos||cmd.find(".D(")!=string::npos||cmd.find(".A(")!=string::npos)
        {
            trim(cmd);
            string tmp=cmd;
            while(cmd.find(";")==string::npos) 
            {
                getline(f1,cmd);
                trim(cmd);
                tmp+=cmd;
            }
            logic.emplace_back(tmp);
        }else if((cmd.find("nand")!=string::npos)||(cmd.find("NAND")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                nandG.push_back(res);
        }else if((cmd.find("nor")!=string::npos)||(cmd.find("NOR")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                norG.push_back(res);
        }else if((cmd.find("nxor")!=string::npos)||(cmd.find("NXOR")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                nxorG.push_back(res);
        }else if((cmd.find("and")!=string::npos)||(cmd.find("AND")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                andG.push_back(res);
        }else if((cmd.find("xor")!=string::npos)||(cmd.find("XOR")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                xorG.push_back(res);
        }else if((cmd.find("or")!=string::npos)||(cmd.find("OR")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                orG.push_back(res);
        }else if((cmd.find("not")!=string::npos)||(cmd.find("NOT")!=string::npos)){
            string res = getSub(cmd);
            if(!res.empty())
                notG.push_back(res);
        }else if((cmd.find("buf")!=string::npos)||(cmd.find("BUF")!=string::npos)){
            string res=getSub(cmd);
            if(!res.empty())
                bufG.push_back(res);
        }
        else if((cmd.find("inv")!=string::npos)||(cmd.find("INV")!=string::npos)){
            string res=getSub(cmd);
            if(!res.empty())
                invG.push_back(res);
        }
    }
    f1.close();

    cout<<"***********************************************************************"<<endl;
    for(int i=0;i<input.size();i++){
        cout<<input[i]<<endl;
    }
    cout<<"***********************************************************************"<<endl;

    cmd=file_name+".bench";
    fstream f2(cmd.c_str(),ios::out);

    f2<<"#"<<endl;
    for(auto& s : input)
    {
        if(s.find(",")!=string::npos)
        {
            int l=0,r=0;
            while(r<s.size())
            {
                while(s[l]==' '||s[l]=='\t'||s[l]=='\n') l++;
                while(s[r]!=','&&s[r]!=';') r++;
                f2<<"INPUT("<<s.substr(l,r-l)<<")"<<endl;
                l=r+1;
                r=l;
            }
        }
        else if(s.find("[")!=string::npos&&s.find(":")!=string::npos)
        {
            int high=0,low=0;
            int l=0,r=0;
            while(s[l]!='[') l++;
            while(s[r]!=':') r++;
            high=stoi(s.substr(l+1,r-l-1));
            l=r;
            r++;
            while(s[r]!=']') r++;
            low=stoi(s.substr(l+1,r-l-1));
            l=r+1;
            r=l;
            while(s[l]==' '||s[l]=='\t'||s[l]=='\n') l++;
            while(s[r]!=','&&s[r]!=';') r++;
            for(int i=low;i<=high;++i)
                f2<<"INPUT("<<s.substr(l,r-l)<<"["<<to_string(i)<<"])"<<endl;
        }
    }

    for(auto& s : output)
    {
        if(s.find(",")!=string::npos||s.find(";")!=string::npos)
        {
            int l=0,r=0;
            while(r<s.size())
            {
                while(s[l]==' '||s[l]=='\t'||s[l]=='\n') l++;
                while(s[r]!=','&&s[r]!=';') r++;
                f2<<"OUTPUT("<<s.substr(l,r-l)<<")"<<endl;
                l=r+1;
                r=l;
            }
        }
        else if(s.find("[")!=string::npos&&s.find(":")!=string::npos)
        {
            int high=0,low=0;
            int l=0,r=0;
            while(s[l]!='[') l++;
            while(s[r]!=':') r++;
            high=stoi(s.substr(l+1,r-l-1));
            l=r;
            r++;
            while(s[r]!=']') r++;
            low=stoi(s.substr(l+1,r-l-1));
            l=r+1;
            r=l;
            while(s[l]==' '||s[l]=='\t'||s[l]=='\n') l++;
            while(s[r]!=','&&s[r]!=';') r++;
            for(int i=low;i<=high;++i)
                f2<<"OUTPUT("<<s.substr(l,r-l)<<"["<<to_string(i)<<"])"<<endl;
        }
    }

    for(auto& s : logic)
    {
        if(s.find("assign")!=string::npos)
        {
            string tmp=s.substr(s.find("assign")+6);
            string src=tmp.substr(0,tmp.find("="));
            string des=tmp.substr(tmp.find("=")+1);

            des.pop_back();

            while(src.back()==' '||src.back()=='\t'||src.back()=='\n') src.pop_back();
            while(src[0]==' '||src[0]=='\t'||src[0]=='\n') src=src.substr(1);

            while(des.back()==' '||des.back()=='\t'||des.back()=='\n') des.pop_back();
            while(des[0]==' '||des[0]=='\t'||des[0]=='\n') des=des.substr(1);

            f2<<src<<" = BUF("<<des<<")"<<endl;
        }
        else if(s.find(".CK(")!=string::npos)
        {
            int l=s.find(".D(")+3;
            while(s[l]==' '||s[l]=='\t'||s[l]=='\n') l++;
            int r=l+1;
            while(s[r]!=')') r++;
            
            string src=s.substr(l,r-l);
            string q="",qn="";

            if(s.find(".Q(")!=string::npos)
            {
                l=s.find(".Q(")+3;
                r=l+1;
                while(s[r]!=')') r++;
                q=s.substr(l,r-l);
            }
            if(s.find(".QN(")!=string::npos)
            {
                l=s.find(".QN(")+4;
                r=l+1;
                while(s[r]!=')') r++;
                qn=s.substr(l,r-l);
            }
            if(q!="")
            {
                f2<<q<<" = DFF("<<src<<")"<<endl;
                if(qn!="")
                {
                    f2<<qn<<" = NOT("<<q<<")"<<endl;
                }
            }
            else if(q=="")
            {
                f2<<"tmp_"<<qn<<" = DFF("<<src<<")"<<endl;
                f2<<qn<<" = NOT(tmp_"<<qn<<")"<<endl;
            }
        }
        else if(s.find(".Y(")!=string::npos)
        {
            string a="",b="",c="",d="",y="";
            string gate="";
            if(s.find("INVX1")!=string::npos) gate="NOT";
            else if(s.find("NAND2X1")!=string::npos||s.find("NAND3X1")!=string::npos||s.find("NAND4X1")!=string::npos) gate="NAND";
            else if((s.find("NAND2X1")==string::npos&&s.find("NAND3X1")==string::npos&&s.find("NAND4X1")==string::npos)&&(s.find("AND2X1")!=string::npos||s.find("AND3X1")!=string::npos||s.find("AND4X1")!=string::npos)) gate="AND";
            else if(s.find("NOR2X1")!=string::npos||s.find("NOR3X1")!=string::npos||s.find("NOR4X1")!=string::npos) gate="NOR";
            else if((s.find("NOR2X1")==string::npos&&s.find("NOR3X1")==string::npos&&s.find("NOR4X1")==string::npos)&&(s.find("OR2X1")!=string::npos||s.find("OR3X1")!=string::npos||s.find("OR4X1")!=string::npos)) gate="OR";
            else if(s.find("BUFX2")!=string::npos) gate="BUF";        

            int l=0,r=0;
            l=s.find(".A(")+3;
            r=l+1;
            while(s[r]!=')') r++;
            a=s.substr(l,r-l);

            l=s.find(".Y(")+3;
            r=l+1;
            while(s[r]!=')') r++;
            y=s.substr(l,r-l);
            trim(y);
            trim(a);
            if(s.find(".B(")==string::npos)
            {
                f2<<y<<" = "<<gate<<"("<<a<<")"<<endl;
                continue;
            }

            l=s.find(".B(")+3;
            r=l+1;
            while(s[r]!=')') r++;
            b=s.substr(l,r-l);
            trim(b);
            if(s.find(".C(")==string::npos)
            {
                f2<<y<<" = "<<gate<<"("<<a<<","<<b<<")"<<endl;
                continue;
            }

            l=s.find(".C(")+3;
            r=l+1;
            while(s[r]!=')') r++;
            c=s.substr(l,r-l);
            trim(c);
            if(s.find(".D(")==string::npos)
            {
                f2<<y<<" = "<<gate<<"("<<a<<","<<b<<","<<c<<")"<<endl;
                continue;
            }

            l=s.find(".D(")+3;
            r=l+1;
            while(s[r]!=')') r++;
            d=s.substr(l,r-l);
            trim(d);
            f2<<y<<" = "<<gate<<"("<<a<<","<<b<<","<<c<<","<<d<<")"<<endl;
        }
    }

    for(auto& g : andG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = AND(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }
    for(auto& g : orG){
        cout<<g<<endl;
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = OR(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }
    for(auto& g : notG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = NOT(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }
    for(auto& g : xorG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = XOR(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }

    for(auto& g : nxorG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = NXOR(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }

    for(auto& g : nandG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = NAND(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }
    for(auto& g : norG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = NOR(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }

    for(auto& g : bufG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = BUF(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }

    for(auto& g : invG){
        vector<string> gList=spiltByD(g);
        int n=gList.size();
        //第一个门是输出门
        f2<<gList[0]<<" = INV(";
        for(int i=1;i<n;i++){
            if(i!=1)f2<<", ";
            f2<<gList[i];
        }
        f2<<")"<<"\n";
    }

    return 0;
}