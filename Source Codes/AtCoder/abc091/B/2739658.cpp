#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	string s[110],t[110];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int res=0;
		for(int j=0;j<n;j++){
			if(s[i]==s[j])res++;
		}
		for(int j=0;j<m;j++){
			if(s[i]==t[j])res--;
		}
		if(res>ans)ans=res;
	}
	cout<<ans<<endl;
}