#include <stdio.h>
int main()
{
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if(N==1)
	{
		if(A==B)
			printf("1");
		else
			printf("0");
	}
	else{
		if(A>B)
			printf("0");
		else
			printf("%lld",(long long)(B-A)*(N-2)+1);
	}
		
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^