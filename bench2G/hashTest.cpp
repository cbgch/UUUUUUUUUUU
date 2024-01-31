#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<memory>

struct weak_ptr_hash
{	
	size_t operator()(const std::weak_ptr<cell>& ptr) const
	{
		return std::hash<std::shared_ptr<cell>>()(ptr.lock());
	}
};

int main(){
    int a=0;
    std::weak_ptr<int> p=&a;
    weak_ptr_hash hs=new weak_ptr_hash();
    std::cout<<hs(p)<<std::endl;
}