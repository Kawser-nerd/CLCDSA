#include <stdio.h>

int main(int argc, char const *argv[])
{
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if((B - A) % 2)	printf("Borys\n");
	else printf("Alice\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^