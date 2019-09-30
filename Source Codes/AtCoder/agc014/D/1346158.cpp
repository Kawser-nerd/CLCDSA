#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read()//?????????? 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=200005;
int nedge,flag,cd[N],n,m,nextt[N],son[N],ed[N];
inline void dfs(int p,int fa){
	if(flag)return; int sum=0;
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa)dfs(ed[i],p);
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa){
		if(!cd[ed[i]])sum++;
	}
	if(sum>1){
		flag=true; return;
	}
	cd[p]=sum;
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; cd[a]++;
	son[a]=nedge;
	ed[nedge]=b;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s1=read(),s2=read();
		aedge(s1,s2); aedge(s2,s1);
	}
	dfs(1,0);
	if(flag||cd[1]==0)puts("First"); else puts("Second");
}