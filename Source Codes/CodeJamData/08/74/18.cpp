#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

#define MAXN 4

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

int m,n;
bool burn[MAXN][MAXN];
bool first[MAXN][MAXN][1<<(MAXN*MAXN)];
bool mrk[MAXN][MAXN][1<<(MAXN*MAXN)];
char buf[100];

void calc(int a,int b,int msk){
	
	int i,nx,ny,k;
	
	if(mrk[a][b][msk]) return ;
	mrk[a][b][msk] = true;
	
	bool ret = false;
	
	for(i=0;i<8;i++){
		nx = a+dx[i];
		if(nx<0||nx>=m) continue;
		ny = b+dy[i];
		if(ny<0||ny>=n) continue;
		k = n*nx+ny;
		if(burn[nx][ny]) continue;
		if(msk & (1<<k)) continue;
		calc(nx,ny,msk|(1<<k));
		ret = ret | (!first[nx][ny][msk|(1<<k)]);
	}
	
	first[a][b][msk] = ret;
	
}

int main(){
	
	int t,lp;
	int bx,by;
	int i,j,k;
	
	scanf("%d",&t);
	
	for(lp=1;lp<=t;lp++){
		scanf("%d %d",&m,&n);
		for(i=0;i<m;i++){
			scanf("%s",buf);
			for(j=0;j<n;j++){
				burn[i][j] = false;
				if(buf[j] == '#'){
					burn[i][j] = true;
				}
				else if(buf[j] == 'K'){
					bx = i;
					by = j;
				}
			}
		}
		
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				for(k=0;k<(1<<(m*n));k++){
					mrk[i][j][k] = false;
				}
				mrk[i][j][(1<<(m*n))-1] = true;
				first[i][j][(1<<(m*n))-1] = false;
			}
		}
		
		calc(bx,by,(1<<(n*bx+by)));
		
		printf("Case #%d: ",lp);
		if(first[bx][by][(1<<(n*bx+by))]){
			printf("%c\n",'A');
		}
		else{
			printf("%c\n",'B');
		}
		
	}
	
	return 0;
	
}

