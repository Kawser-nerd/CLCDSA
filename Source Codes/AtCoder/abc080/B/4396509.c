#include <stdio.h>
#include <string.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int i,temp=n,f=0;
	for(i=100000000;i >= 1;i /= 10)
		{
		f += temp/i;
		temp %= i;
		//printf("i=%d f=%d temp=%d\n",i,f,temp);
		}

	if(n % f == 0)
		{printf("Yes\n");}
	else
		{printf("No\n");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^