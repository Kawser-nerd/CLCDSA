#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 200005
#define N 262144
int n,m,num[MN],f[MN],t[N*2+5],a[MN];
vector<int> v[MN];
inline void rw(int x,int v){for(x+=N+1;t[x]=min(t[x],v),x>>=1;);}
inline int query(int l,int r){
	int res=1e9;
	for(l+=N,r+=N+2;l^r^1;l>>=1,r>>=1){
		if(~l&1) res=min(res,t[l+1]);
		if( r&1) res=min(res,t[r-1]);
	}
	return res;
}
int main(){
	n=read();register int i,j;
	for(i=1;i<=n;++i) num[i]=num[i-1]+1-(a[i]=read()),f[i]=1e9;
	m=read();memset(t,63,sizeof t);int l;
	for(i=1;i<=m;++i) l=read(),v[l-1].push_back(read());
	for(i=0;i<n;++i){
		f[i+1]=min(f[i+1],f[i]+a[i+1]);
		for(j=0;j<v[i].size();++j){
			int w=min(f[i]+num[v[i][j]]-num[i],query(i,v[i][j])+num[v[i][j]]);
			f[v[i][j]]=min(f[v[i][j]],w);
			rw(v[i][j],w-num[v[i][j]]); 
		}
	}
	printf("%d\n",f[n]);
} ./Main.cpp:26:11: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        n=read();register int i,j;
                 ^~~~~~~~~
./Main.cpp:26:11: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        n=read();register int i,j;
                 ^~~~~~~~~
2 warnings generated.