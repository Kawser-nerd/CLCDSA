#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

const int MAXN=105;
int T,N,M;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int parent[MAXN*MAXN],rank[MAXN*MAXN];
inline void reset() {
	for(int i=0;i<N*M;i++) {
		parent[i]=i;
		rank[i]=0;
	}
}

inline int find(int x) {
	return (x==parent[x] ? x : parent[x]=find(parent[x]));
}

inline void unite(int x,int y) {
	x=find(x);
	y=find(y);
	if (rank[x]>=rank[y]) {
		parent[y]=x;
		if (rank[x]==rank[y]) {rank[x]++;}
	}	else {
		parent[x]=y;
	}
}

int grid[MAXN][MAXN];
char ans[MAXN][MAXN];
inline bool valid(int x,int y) {return (x>=0 && x<N && y>=0 && y<M);}

int main() {
	scanf("%d ",&T);
	for(int t=1;t<=T;t++) {
		scanf("%d %d ",&N,&M);
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				scanf("%d",&grid[i][j]);
			}
		}
		reset();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				int lowest=grid[i][j];
				int best=-1;
				for(int d=0;d<4;d++) {
					int r=i+dx[d],c=j+dy[d];
					if (valid(r,c) && grid[r][c]<lowest) {
						lowest=grid[r][c];
						best=r*M+c;
					}
				}
				if (best!=-1) {
					unite(best,i*M+j);
				}
			}
		}
		printf("Case #%d:\n",t);
		map<int,char> mem;
		char it='a';
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if (j>0) {printf(" ");}
				int v=find(i*M+j);
				if (mem.find(v)==mem.end()) {
					mem[v]=it++;
				}
				printf("%c",mem[v]);
			}
			printf("\n");
		}
	}
	return 0;
}
