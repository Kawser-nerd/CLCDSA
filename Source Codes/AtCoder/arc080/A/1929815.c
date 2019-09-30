#include <stdio.h>
int main(void)
{
	int n,i,m=0,p=0,q=0;
	long long a[100000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]%4==0)
		  m++;
		else if(a[i]%2==0)
		  p++;
		else
		  q++;
	}
	if(m-q>=0||(m-q==-1)&&p==0)
	  printf("Yes");
	else
	  printf("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i]);
   ^