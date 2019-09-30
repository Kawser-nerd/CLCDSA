#include<stdio.h>
#include<math.h>
int main()
{
	int N,f[100][10],i,j,x,y,a[10];
	int count;
	long long p[100][11],sum,max;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<10;j++)
		{
			scanf("%d",&f[i][j]);
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<11;j++)
		{
			scanf("%lld",&p[i][j]);
		}
	}
	
	for(x=1;x<=1023;x++)
	{
		sum=0;
		y=x;
		a[0]=y/(pow(2,9));
		for(i=1;i<10;i++)
		{
			y-=a[i-1]*pow(2,10-i);
			a[i]=y/(pow(2,9-i));
		}
		
		for(i=0;i<N;i++)
		{
			count=0;
			for(j=0;j<10;j++)
			{
				if((f[i][j]==1)&&(a[j]==1))
					count++;
			}
			sum+=p[i][count];
		}
		if(x==1) max=sum;
		if(sum>max) max=sum;
	}
	printf("%lld",max);
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&f[i][j]);
    ^
./Main.c:20:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld",&p[i][j]);
    ^