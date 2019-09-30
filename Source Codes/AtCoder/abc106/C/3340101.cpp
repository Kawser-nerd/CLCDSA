#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
int main(){
	string s;
	int k;
	cin>>s;
	cin>>k;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(i+1==k){cout<<s[i];break;}
		if(s[i]!='1'){cout<<s[i];break;}
		if(i+1==l){cout<<1;break;}
	}
	return 0;
}