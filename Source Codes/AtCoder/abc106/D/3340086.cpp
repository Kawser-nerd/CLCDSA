#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
int d[555][555]={0},c[555][555]={0};
int qu(int l,int r){
	if(l>r)return 0;
	if(d[l][r]!=-1)return d[l][r];
	return d[l][r]=c[l][r]+qu(l+1,r)+qu(l,r-1)-qu(l+1,r-1);
}
int main(){
	memset(d,-1,sizeof(d));
	int n,m,q;
	cin>>n>>m>>q;
	while(m--){
		int l,r;
		cin>>l>>r;
		c[l][r]++;
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<qu(l,r)<<endl;
	}
	return 0;
}