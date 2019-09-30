#include<stdio.h>
	int main()
{
	int i,n,m;
	scanf("%d",&n);
	for(i=2;1;i++)
	{
		m=n%i;
		if(m==0)
		break;
	}
	if(i==n)
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
	
	
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^