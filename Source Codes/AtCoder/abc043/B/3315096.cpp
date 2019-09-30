#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
string a;
char c[100];
int top=1;
int main(){
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]=='B')top--;
		if(top==0)top=1;
		if(a[i]!='B') c[top++]=a[i];
	}
	for(int i=1;i<top;i++)cout<<c[i];
	return 0;
}