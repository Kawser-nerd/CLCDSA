#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define INF 1000000000

char map[110][110];
void read(int w,int h,char c){
	int i,j;
	scanf("%*c");
	FOR(i,0,h+2) map[0][i]=c,map[w+1][i]=c;
	FOR(i,0,w+2) map[i][0]=c,map[i][h+1]=c;
	FOR(i,1,h+1){
		FOR(j,1,w+1){
	        scanf("%c",&map[j][i]);
	        //if(map[j][i]=='S') sx=j,sy=i,map[j][i]='.';
	    }
        scanf("%*c");
    }
    return; 
}
int dp[101][101];
int used[101][101];
int dfs(int x,int y){
	if(used[x][y]) return dp[x][y];
	used[x][y]=1;
	if(map[x+1][y]!='#') dp[x][y]|=!dfs(x+1,y);
	if(map[x][y+1]!='#') dp[x][y]|=!dfs(x,y+1);
	if(map[x+1][y+1]!='#') dp[x][y]|=!dfs(x+1,y+1);
	return dp[x][y];
}
int main(void){
	int h,w;
	scanf("%d%d",&h,&w);
	read(w,h,'#');
	printf("%s\n",dfs(1,1)?"First":"Second");
	return 0;
} ./Main.c: In function ‘read’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*c");
  ^
./Main.c:14:10: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
          scanf("%c",&map[j][i]);
          ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%*c");
         ^
./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^