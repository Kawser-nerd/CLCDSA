#include<iostream>
#include<cstdio>  
#include<cstring>  
using namespace std;  
string a,b;  
int main()  
{ 
    cin>>a>>b;
    if(a.size()>b.size())cout<<"GREATER"<<endl;
     else if(a.size()<b.size())cout<<"LESS"<<endl;
     else if(a.size()==b.size())
	 {
	 	if(a>b)cout<<"GREATER"<<endl;
     if(a<b)cout<<"LESS"<<endl;
     if(a==b)cout<<"EQUAL"<<endl;
	 }
	return 0;
}