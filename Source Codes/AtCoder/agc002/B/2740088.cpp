#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)
int main(){
	int n,m;
	cin>>n>>m;
	int x[100010],y[100010];
	bool b[100010];
	rep(i,n){
		b[i]=false;
	}
	b[1]=true;	
	int c[100010];
	rep(i,n){
		c[i+1]=1;
	}	
	rep(i,m){
		cin>>x[i]>>y[i];
		if(b[x[i]]){
			b[y[i]]=true;
		}
		int s=x[i];
		int t=y[i];
		c[s]--;
		c[t]++;	
		if(!c[x[i]])b[x[i]]=false;
	}
	int ans=0;
	rep(i,n){
		if(b[i+1]==true)ans++;
	}
	cout<<ans<<endl;
	
}