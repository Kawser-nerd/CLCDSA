#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int c[10000];
string a;
int main(){
	cin>>a;
	for(int i=1;i<=1000;i++)c[i]=0;
	for(int i=0;i<a.size();i++)c[a[i]]++;
	//cout<<endl;
	for(int i='a';i<='z';i++)if(c[i]%2!=0)c[1]++;
	//for(int i='a';i<='z';i++)cout<<c[i]<<' ';
	//cout<<endl;
	//cout<<c[1]<<endl;
	if(!c[1])cout<<"Yes";
	else cout<<"No";
	return 0;
}