#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
int n,ans=1,m[100066];
int main(){
	cin>>n;
	bool jia=false,jian=false,flag=false;
	for(int i=1;i<=n;i++)cin>>m[i];
	for(int i=1;i<=n;i++){
		if(jia==false&&jian==false&&m[i]!=m[i+1]){
			if(m[i+1]>m[i])jia=true;
			else if(m[i+1]<m[i])jian=true;
		}
		if(i!=1) {
			if(m[i]==m[i-1])continue;
			else if(m[i]>m[i-1]){
				if(jia==false&&jian==true){
					ans++;jian=false;
				}
			}
			else if(m[i]<m[i-1]){
				if(jian==false&&jia==true){
					ans++;jia=false;
				}
			}
		}
		if(jia==false&&jian==false&&m[i]!=m[i+1]){
			if(m[i+1]>m[i])jia=true;
			else if(m[i+1]<m[i])jian=true;
		}
	}
	cout<<ans;
	return 0;
}