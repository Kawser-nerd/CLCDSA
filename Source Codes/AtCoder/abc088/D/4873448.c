#include <stdio.h>
#include <stdlib.h>
#define INF -1e9

typedef struct{
	int x,y;
}coordinate;

int H,W;
int d[50][50];
char s[50][51];


int bfs(){
	int i,j;
	int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	int sx=0,sy=0,gx=H-1,gy=W-1;
	
	for(i=0;i<H;i++)for(j=0;j<W;j++)d[i][j]=INF;
	d[sx][sy]=0;
	coordinate visit[2500]={0};
	int queH=0,queT=0;
	visit[queH].x = sx;
	visit[queH].y = sy;
	queT++;
	
	while(queT>queH){
		int px=visit[queH].x,py=visit[queH++].y;
		if(px==gx && py==gy)break;
		for(i=0;i<4;i++){
			int nx = px+dx[i], ny = py+dy[i];
			if(0<=nx && nx<H && 0<=ny && ny<W && s[nx][ny]!='#' && d[nx][ny]==INF){
				visit[queT].x = nx;
				visit[queT++].y = ny;
				d[nx][ny] = d[px][py]+1;
			}
		}
	}
	return d[gx][gy];
	}
	

int main(void){
	int i,j;
	scanf("%d%d",&H,&W);
	int white = 0;
	
	for(i=0;i<H;i++){scanf("%s",&s[i]);}
	for(i=0;i<H;i++)for(j=0;j<W;j++)if(s[i][j] == '.')white++;
	
	int p = bfs();
	if(p==INF)printf("-1");
	else printf("%d",white-p-1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:25: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
  for(i=0;i<H;i++){scanf("%s",&s[i]);}
                         ^
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:48:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<H;i++){scanf("%s",&s[i]);}
                   ^