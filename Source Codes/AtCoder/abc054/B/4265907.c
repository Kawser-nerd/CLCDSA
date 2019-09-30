#include <stdio.h>

int main(void)
{
	int n,m,i,j,k,l,check;
	scanf("%d%d",&n,&m);
	char a[n][n+1],b[m][m+1];
	for(i=0;i<=n-1;i++)
			{scanf("%s",a[i]);}
		
	i=0;
	for(i;i<=m-1;i++)
			{scanf("%s",b[i]);}

	fprintf(stderr,"\nA is  below\n");	/* check A */
	i=0;
	for(i;i<=n-1;i++)
		{
		fprintf(stderr,"%s",a[i]);
		fprintf(stderr,"\n");
		}
	fprintf(stderr,"\nB is  below\n");	/* check B*/
	i=0;
	for(i;i<=m-1;i++)
		{
		fprintf(stderr,"%s",b[i]);
		fprintf(stderr,"\n");
		}
						/* search */
	for(i=0;i<=n-m;i++)
		{
		for(j=0;j<=n-m;j++)
			{
			check=1;
			for(l=0;l<=m-1;l++)
				{
				for(k=0;k<=m-1;k++)
					{
					if(a[i+k][j+l] != b[k][l])
						{check=0;break;}
					}
					if(check==0){break;}
				}
			if(check==1){break;}
			}
		if(check==1){break;}
		}
	
	if(check==1)
		{printf("Yes\n");}
	else
		{printf("No\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    {scanf("%s",a[i]);}
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    {scanf("%s",b[i]);}
     ^