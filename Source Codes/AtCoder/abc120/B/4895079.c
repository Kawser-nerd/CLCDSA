#include <stdio.h>

int main(void)
{

	int a,b,k,tmp,i,n;

	n=0;

	scanf("%d%d%d",&a,&b,&k);

	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}

	for(i=a; i>=1; i--)
	{
		if((b%i==0)&&(a%i==0)) n=n+1;
		if(n==k)
		{
			printf("%d",i);
			break;
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&k);
  ^