#include<stdio.h>

int main(){
		int r,c,startx,starty,goalx,goaly;
		scanf("%d %d %d %d %d %d",&r,&c,&starty,&startx,&goaly,&goalx);
		int i=0,j=0;
		char map[r][c+5];
		for(i=0;i<r;i++){
				scanf("%s",map[i]);
		}
		int nowx,nowy;
		int queuexy[10000][2];long quehajime=0,queowari=0;
		int saitan[c][r];
		for(i=0;i<r;i++){
				for(j=0;j<c;j++){
						if(map[i][j]=='.')saitan[j][i]=-1;
						else saitan[j][i]=-10;
				}
		}
		saitan[startx-1][starty-1]=0;
		nowx=startx-1;
		nowy=starty-1;
		int keizokuflag=0;
		while(1){
				keizokuflag=0;
				if(map[nowy-1][nowx]=='.'&&
				(saitan[nowx][nowy-1]==-1
				 /*saitan[nowx][nowy-1]>=saitan[nowx][nowy]+1*/)){
						queuexy[queowari][0]=nowx;
						queuexy[queowari][1]=nowy-1;
						queowari++;
						saitan[nowx][nowy-1]=saitan[nowx][nowy]+1;
				//		puts("ok1");
				}
				if(map[nowy][nowx-1]=='.'&&
				(saitan[nowx-1][nowy]==-1
				 /*saitan[nowx-1][nowy]>=saitan[nowx][nowy]+1*/)){
						queuexy[queowari][0]=nowx-1;
						queuexy[queowari][1]=nowy;
						queowari++;
						saitan[nowx-1][nowy]=saitan[nowx][nowy]+1;
				//		puts("ok2");
				}
				if(map[nowy+1][nowx]=='.'&&
				(saitan[nowx][nowy+1]==-1
				 /*saitan[nowx][nowy+1]>=saitan[nowx][nowy]+1*/)){
						queuexy[queowari][0]=nowx;
						queuexy[queowari][1]=nowy+1;
						queowari++;
						saitan[nowx][nowy+1]=saitan[nowx][nowy]+1;
				//		puts("ok3");
				}
				if(map[nowy][nowx+1]=='.'&&
				(saitan[nowx+1][nowy]==-1
				 /*saitan[nowx+1][nowy]>=saitan[nowx][nowy]+1*/)){
						queuexy[queowari][0]=nowx+1;
						queuexy[queowari][1]=nowy;
						queowari++;
						saitan[nowx+1][nowy]=saitan[nowx][nowy]+1;
				//		puts("ok4");
				}
				for(i=0;i<r;i++){
						if(keizokuflag==1)break;
						for(j=0;j<c;j++){
								if(map[i][j]=='.'&&saitan[j][i]==-1){
										keizokuflag=1;
										break;
								}
						}
				}
				//puts("ok-1");
				nowx=queuexy[quehajime][0];
				nowy=queuexy[quehajime][1];
				if(quehajime<queowari)quehajime++;
				else break;
				if(keizokuflag==0)break;
		}
		printf("%d\n",saitan[goalx-1][goaly-1]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d %d",&r,&c,&starty,&startx,&goaly,&goalx);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",map[i]);
     ^