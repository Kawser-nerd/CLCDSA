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
int l,r,quex[1000000],quey[1000000],que[1000000],ans=10000000,n,m,k,S1[4]={0,0,1,-1},S2[4]={1,-1,0,0},s1,s2;
bool vis[1000][1000];
char ch[1000][1000];
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)scanf("\n%c",&ch[i][j]);
		for(int j=1;j<=m;j++)if(ch[i][j]=='S'){
			s1=i; s2=j;
		}
	}
	quex[l=r=1]=s1; quey[1]=s2;
	while(l<=r){int x=quex[l],y=quey[l]; int zs=que[l++];// cout<<x<<" "<<y<<endl;
	if(x==1||x==n||y==1||y==m){
		ans=min(ans,1); break;
	}
	ans=min(ans,1+min((x-2)/k+1,min((y-2)/k+1,min((n-x-1)/k+1,(m-y-1)/k+1))));
	if(zs<k)for(int i=0;i<4;i++)if(!vis[x+S1[i]][y+S2[i]]&&ch[x+S1[i]][y+S2[i]]!='#'){
		quex[++r]=x+S1[i];quey[r]=y+S2[i]; que[r]=zs+1; vis[x+S1[i]][y+S2[i]]=true;
	}
	}
	writeln(ans);
}