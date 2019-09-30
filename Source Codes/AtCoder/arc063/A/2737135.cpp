#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define inf 1e9
#define eps 1e-10
#define mod 9901
#define mkp make_pair
using namespace std;
int i,j,k,m,s,t,n,ans1,ans2,n1,nn,m1,mx;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int kabs(int a)
{
   if (a<0) return -a;
   return a; 
}
void add(int &x,int y)
{
   x+=y;
   if (x>=mod) x-=mod;
}
void dec(int &x,int y)
{
	x-=y;
	if (x<0) x+=mod;
}
char ch[101000];
int main()
{
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for (i=2;i<=n;i++)
		if (ch[i]!=ch[i-1])
			s++;
	printf("%d\n",s);
}