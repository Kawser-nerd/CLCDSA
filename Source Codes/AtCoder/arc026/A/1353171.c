#include <stdio.h>


int main ()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	int time;
	if(n<=5)
	{
		time = b*n;
	}
	else{
		time = 5*b+(n-5)*a;
	}
	printf("%d\n",time);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&a,&b);
  ^