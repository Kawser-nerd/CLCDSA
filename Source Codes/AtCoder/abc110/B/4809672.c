#include <stdio.h>
int main(void){
	int N,M,X,Y,i;
	int x[101];
	int y[101];
	scanf("%d %d %d %d",&N,&M,&X,&Y);
	int xmax=X;
	int ymin=Y;
	for(i=0;i<N;i++){
		scanf("%d",&x[i]);
		if(xmax<x[i])xmax=x[i];
	}
	for(i=0;i<M;i++){
		scanf("%d",&y[i]);
		if(ymin>y[i])ymin=y[i];
	}
	if(xmax<ymin){
		printf("No War");
	}else{
		printf("War");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&N,&M,&X,&Y);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x[i]);
   ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&y[i]);
   ^