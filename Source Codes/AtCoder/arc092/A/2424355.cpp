#include<set>   
#include<map>  
#include<stack> 
#include<cmath>   
#include<cstdio>   
#include<queue>   
#include<vector>   
#include<climits>   
#include<cstring>   
#include<iostream>   
#include<algorithm>   
using namespace std;
#define MAXN 100
#define INF 0x3f3f3f3f 
int read()  
{  
    int f=1,x=0;  
    char c=getchar();  
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}  
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}  
    return f*x;  
}
struct node{
	int x,y;
}red[MAXN+5],blue[MAXN+5];
bool vis[2*MAXN+5];
vector<int> G[2*MAXN+5];
int n,match[2*MAXN+5];
bool DFS(int u){
	for(int i=0;i<int(G[u].size());i++){
		int v=G[u][i];
		if(vis[v]) continue;
		vis[v]=1;
		if(!match[v]||DFS(match[v]))
		{
			match[v]=u;
			match[u]=v;
			return 1;
		}
	}
	return 0;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		red[i].x=read(),red[i].y=read();
	for(int i=1;i<=n;i++)
	{
		blue[i].x=read(),blue[i].y=read();
		for(int j=1;j<=n;j++)
			if(red[j].x<blue[i].x&&red[j].y<blue[i].y)
				G[n+i].push_back(j),G[j].push_back(n+i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!match[i])
		{
			memset(vis,0,sizeof vis);
			if(DFS(i)) ans++;
		}
	printf("%d\n",ans);
	return 0;  
} /**/