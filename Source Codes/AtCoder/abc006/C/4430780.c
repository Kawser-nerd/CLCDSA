#include<stdio.h>

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	if(M%2 == 1 && 4*N-M-1>=0 && M-2*N-1>=0)
		printf("%d 1 %d",(4*N-M-1)/2,(M-2*N-1)/2);
	else if(M % 2 == 0 && 4*N-M>=0 && M-2*N>=0)
		printf("%d 0 %d",(4*N-M)/2,(M-2*N)/2);
	else printf("-1 -1 -1");
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^