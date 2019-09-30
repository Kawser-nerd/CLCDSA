#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
char map[10][11];
char s[10][11];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int x,int y){
	int nx,ny,i;
	s[x][y]='x';
	FOR(i,0,4){
		nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&ny>=0&&nx<10&&ny<10&&s[nx][ny]=='o'){
			dfs(nx,ny);
		}
	}
	return;
}
int check(){
	int cnt=0,i,j;
	FOR(i,0,10) strcpy(s[i],map[i]);
	FOR(i,0,10){
		FOR(j,0,10){
			if(s[i][j]=='o'){
				cnt++;
				dfs(i,j);
			}
		}
	}
	return cnt==1;
}
int main(void)
{
	int i,j;
	FOR(i,0,10) scanf("%s",map[i]);
	FOR(i,0,10){
		FOR(j,0,10){
			if(map[i][j]=='x'){
				map[i][j]='o';
				if(check()){
					puts("YES");
					return 0;
				}
				map[i][j]='x';
			}
		}
	}
	puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,10) scanf("%s",map[i]);
              ^