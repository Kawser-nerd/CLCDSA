#include<queue>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
 
struct A{
	int x,y;
};
 
queue<A>Q;

char a[810][810];
int vis[810][810],in[810][810],n,m,K;
 
void bfs(int x,int y){
	Q.push((A){x,y});
	vis[x][y]=0;
	while(!Q.empty()){
		A p=Q.front();Q.pop();int x,y,d=vis[p.x][p.y];in[p.x][p.y]=0;
		x=p.x-1;y=p.y;if(x>0&&y>0&&x<=n&&y<=m&&d+1<=K&&d+1<vis[x][y]&&a[x][y]!='#'){vis[x][y]=d+1;if(!in[x][y]){Q.push((A){x,y});in[x][y]=1;}}
		x=p.x+1;y=p.y;if(x>0&&y>0&&x<=n&&y<=m&&d+1<=K&&d+1<vis[x][y]&&a[x][y]!='#'){vis[x][y]=d+1;if(!in[x][y]){Q.push((A){x,y});in[x][y]=1;}}
		x=p.x;y=p.y-1;if(x>0&&y>0&&x<=n&&y<=m&&d+1<=K&&d+1<vis[x][y]&&a[x][y]!='#'){vis[x][y]=d+1;if(!in[x][y]){Q.push((A){x,y});in[x][y]=1;}}
		x=p.x;y=p.y+1;if(x>0&&y>0&&x<=n&&y<=m&&d+1<=K&&d+1<vis[x][y]&&a[x][y]!='#'){vis[x][y]=d+1;if(!in[x][y]){Q.push((A){x,y});in[x][y]=1;}}
	}
}
 
int Que(int x,int y){
	return min(min(x-1,y-1),min(n-x,m-y));
}
 
int main(){
	int x,y;
	scanf("%d %d %d",&n,&m,&K);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++){
			if(a[i][j]=='S')x=i,y=j;
		}
	}memset(vis,63,sizeof(vis));
	bfs(x,y);
	int minn=1<<30;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]!=vis[0][0])minn=min(minn,Que(i,j));
		}
	}if(minn==0)printf("1\n");
	else printf("%d\n",1+(minn-1)/K+1);
	return 0;
}