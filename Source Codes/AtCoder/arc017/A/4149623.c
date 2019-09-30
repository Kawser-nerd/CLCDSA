#include<stdio.h>
#include<math.h>
//#define scan
int main()
{
	int a,k,i;
	scanf("%d",&a);
#ifdef scan
	printf("%d",a);
#endif
	if(a==1)printf("NO\n");
	else if(a==2)printf("YES\n");
	else
	{
		k=sqrt(a);
		for(i=2;i<=k;i++)
		{
			if(a%i==0)break;
		}
		if(i>k)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^