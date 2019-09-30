#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	long long n,a[100010],i,k=1,flag=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<n;i++)
	{
		if(flag==0)
		{
			if(a[i]==a[i-1])
				continue;
			else if(a[i]>a[i-1])
				flag=1;
			else
				flag=2;
		}
		else if(a[i]==a[i-1]||flag==1&&a[i]>a[i-1]||flag==2&&a[i]<a[i-1])
			continue;
		else
		{
			flag=0;
			k++;
		}
	}
	printf("%lld",k);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^