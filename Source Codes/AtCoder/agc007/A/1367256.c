#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
char map[10][10];
void read(int w,int h,char c){
	int i,j;
	scanf("%*c");
	FOR(i,0,h+2) map[0][i]=c,map[w+1][i]=c;
	FOR(i,0,w+2) map[i][0]=c,map[i][h+1]=c;
	FOR(i,1,h+1){
		FOR(j,1,w+1){
			scanf("%c",&map[j][i]);
		}
		scanf("%*c");
	}
    return; 
}
int main(void)
{
	int h,w,x=1,y=1,i,j;
	scanf("%d%d",&h,&w);
	read(w,h,'.');
	map[x][y]='.';
	while(1){
		if(map[x+1][y]=='#') map[++x][y]='.';
		else if(map[x][y+1]=='#') map[x][++y]='.';
		else break;
	}
	FOR(i,1,h+1){
		FOR(j,1,w+1){
			if(map[j][i]=='#'){
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	return 0;
} ./Main.c: In function ‘read’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*c");
  ^
./Main.c:27:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&map[j][i]);
    ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%*c");
   ^
./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^