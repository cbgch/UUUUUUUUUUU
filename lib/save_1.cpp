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

int main(int argc,char** argv)//main.exe btb
{
    string file_name=argv[1];
    string cmd="";

    vector<string> input,output,logic;

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
        }
    }
    f1.close();

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
    return 0;
}