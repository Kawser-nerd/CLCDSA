#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
const int N=305;
int n,m,a[N][N],tong[N],t[N],sum;
inline bool check(int x){
	int zs=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(tong[a[i][j]]){t[a[i][j]]++; break;}
	for(int i=1;i<=m;i++){if(t[i]>x){tong[i]=0;sum--;zs=1;} t[i]=0;}
	if(!zs)return 1; else if(!sum)return 0;
	return check(x);
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=read();
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1; for(int i=1;i<=m;i++)tong[i]=1; sum=m;
		if(check(mid))r=mid; else l=mid+1;
	}
	writeln(l);
}