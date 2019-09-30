#include<stdio.h>
#include<string.h>

int main()
{
int test,m,i,start,end,j;
scanf("%d",&test);
m=test;
while(m--)
{
int n,a;
int rec[3000]={0};
scanf("%d",&n);
for(i=0;i<2*n-1;i++)
	{
	for(j=0;j<n;j++)
		{
		scanf("%d",&a);
		rec[a]++;
		}
	}
	printf("Case #%d:",test-m);
	for(i=1;i<3000;i++)
		if(rec[i]&1)printf(" %d",i);
	printf("\n");
	
}
return 0;
}
