#include <stdio.h>

int main(void)
{	int i,j,temp,sub,sum=0;
	int a[4];
	for(i=0;i<=2;i++)
		{scanf("%d",&a[i]);}
	for(i=0;i<=2;i++)
		{fprintf(stderr,"%d ",a[i]);}
	for(i=0;i<=1;i++)
		{
		for(j=0;j<=1-i;j++)
			{
			if(a[j]>a[j+1])
				{temp=a[j],a[j]=a[j+1],a[j+1]=temp;}
			}
		}
	for(i=0;i<=1;i++)
		{sub=a[i+1]-a[i],sum+=sub;}
	printf("%d",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   {scanf("%d",&a[i]);}
    ^