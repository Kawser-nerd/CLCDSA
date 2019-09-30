#include<stdio.h>
int main()
{
	int t=1;
	//scanf("%d",&t);
	int a[t][3],i,j,max,count=0;
	for(i=0;i<t;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<t;i++)
	{
		max=a[i][0];
		count=0;
		for(j=0;j<3;j++)
			if(a[i][j]>max)
				max=a[i][j];
		for(j=0;j<3;j++)
			count+=(max-a[i][j]);
		if(count%2==0)
			count=(0.5*count);
		else
			count=(0.5*count)+2;
		printf("%d\n",count);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^