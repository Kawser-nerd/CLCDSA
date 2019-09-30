#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=21;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int oo=101;
int h[maxn][maxn];
int w[maxn][maxn];
int t[maxn][maxn];
int n,m,d;

void init(){
	scanf("%d%d%d",&n,&m,&d);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&h[i][j]);
		}
	}
	return;
}

bool outside(int x,int y){
	return (x<1)||(x>n)||(y<1)||(y>m);
}

void flow(int x,int y){
	for (int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (outside(tx,ty)){
			continue;
		}
		if ((h[tx][ty]+w[tx][ty])<=(h[x][y]+w[x][y])){
			continue;
		}
		w[tx][ty]=max(0,h[x][y]+w[x][y]-h[tx][ty]);
		flow(tx,ty);
	}
	return;
}

void getwater(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			w[i][j]=oo;
		}
	}
	for (int i=1;i<=n;i++){
		w[i][1]=0;
		flow(i,1);
		w[i][m]=0;
		flow(i,m);
	}
	for (int i=2;i<m;i++){
		w[1][i]=0;
		flow(1,i);
		w[n][i]=0;
		flow(n,i);
	}
	return;
}

void output(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%d ",w[i][j]);
		}
		puts("");
	}
	puts("");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			printf("%d ",h[i][j]);
		}
		puts("");
	}
	return;
}

int getmin(int x,int y){
	int ans=oo;
	for (int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (outside(tx,ty)){
			ans=0;
			break;
		}
		ans=min(ans,h[tx][ty]+w[tx][ty]);
	}
	return ans;
}

int calc(){
	bool stupid=false;
		
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
		
				if (h[i][j]>0){
					stupid=true;
				}
			}
		}
		if (!stupid){
			return 0;
		}
	for (int k=1;;k++){
		getwater();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				int lvl=getmin(i,j);
				t[i][j]=h[i][j]-min(d,h[i][j]+w[i][j]-lvl);
			}
		}
		bool flag=false;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				h[i][j]=t[i][j];
				if (h[i][j]>0){
					flag=true;
				}
			}
		}
		if (!flag){
			return k;
		}
	}
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %d\n",i,calc());
	}
	return 0;
}