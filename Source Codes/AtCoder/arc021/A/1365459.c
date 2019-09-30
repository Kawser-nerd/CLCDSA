#include<stdio.h>
int main(){
	int i,d[5][5]={};
	for(i=0;i<16;i++)scanf(" %d",&d[i/4][i%4]);
	for(i=0;i<16;i++){
		if(d[i/4][i%4]==d[i/4][i%4+1]||d[i/4][i%4]==d[i/4+1][i%4])break;
	}
	printf("%s\n",i-16?"CONTINUE":"GAMEOVER");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<16;i++)scanf(" %d",&d[i/4][i%4]);
                   ^