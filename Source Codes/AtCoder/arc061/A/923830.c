#include<stdio.h>

int main(void)
{
	long long n,i,j,k,d[20],a;
	char s[20];
  
	scanf("%s",s);
  
	for(i=0;s[i];i++)
		d[i]=s[i]-'0';//printf("%d\n",i);
	for(j=a=0;j<(1<<(i-1));j++)
	{
		n=d[0];
		for(k=0;k<i-1;k++)
		{
			if(j&(1<<k))n=n*10+d[k+1];
			else
			{
				a+=n;//printf("%d\n",n);
				n=d[k+1];
			}
		}
    a+=n;
	}
  printf("%lld\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^