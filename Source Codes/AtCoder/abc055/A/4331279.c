#include<stdio.h>
int main()
{
	int pay,back,N;
	scanf("%d",&N);
	pay=N*800;
	back=(N/15)*200;
	//printf("%d %d",pay,back);
	printf("%d",pay-back);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^