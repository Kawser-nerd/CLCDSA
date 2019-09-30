#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
int n,m,fa[200010],du[200010],vis[200010],c[200010];
inline int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}
int main()
{
	n=read();m=read();
	for(int i=1;i<=1000;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		int a=read(),b=read(),c=read(),d=read();
		int x=(c==0)?a:-c,y=(d==0)?-b:d;
		x+=500;y+=500;int fx=getfather(x),fy=getfather(y);
		fa[fx]=fy;vis[x]=1;du[x]++;du[y]--;
	}
	bool flag=1;
	for(int i=1;i<500;i++)if(du[i]>0)flag=0;
	for(int i=501;i<=1000;i++)if(du[i]<0)flag=0;
	for(int i=1;i<=1000;i++){
		int fi=getfather(i);
		vis[fi]|=vis[i];
		if(du[i])c[fi]=1;
	}
	for(int i=1;i<=1000;i++)if(fa[i]==i&&!c[i]&&vis[i])flag=0;
	puts(flag?"YES":"NO");
	return 0;
}