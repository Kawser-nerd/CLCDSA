#include <stdio.h>
#include <stdlib.h>

int cost(int i,int j,int x,int y){return abs(i-x)+abs(j-y);}

int main(void){
	int H,W,D,Q,i,j;
	scanf("%d%d%d",&H,&W,&D);
	int xy[90001][2]={0},d[90001]={0};
	for(i=1;i<=H;i++){
		for(j=1;j<=W;j++){
			int a;
			scanf("%d",&a);
			xy[a][0] = i;
			xy[a][1] = j;
		}
	}
	for(i=D+1;i<=H*W;i++){
		d[i] = d[i-D] + cost(xy[i][0],xy[i][1],xy[i-D][0],xy[i-D][1]);
	}
	scanf("%d",&Q);
	while(Q--){
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%d\n",d[R]-d[L]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&H,&W,&D);
  ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a);
    ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&Q);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&L,&R);
   ^