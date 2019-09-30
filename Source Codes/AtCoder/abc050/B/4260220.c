#include <stdio.h>

int main(void)
{
	int n,m;
	scanf("%d",&n);
	fprintf(stderr,"\nn=%d\n",n);

	int time[n+1];
	int j;
	for (j=0;j<=n-1;j++)
		{scanf("%d",&time[j]);}
	scanf("%d",&m);
	fprintf(stderr,"m=%d\n",m);

	int px[m][3];
	int h=0,i=0;
	for(i;i<=m-1;i++)
		{
		h=0;
		for(h;h<=1;h++)
			{scanf("%d",&px[i][h]);}
		}

	int sumorg=0;
	i=0;	
	for(i;i<=n-1;i++)
			{sumorg += time[i];}
	int sum;
	fprintf(stderr,"sumrog=%d\n",sumorg);
	
	i=0;
	for(i;i<=m-1;i++)
		{
		sum = sumorg + px[i][1]-time[px[i][0]-1];
		printf("%d\n",sum);
		}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   {scanf("%d",&time[j]);}
    ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    {scanf("%d",&px[i][h]);}
     ^