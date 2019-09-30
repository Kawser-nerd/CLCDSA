#include<stdio.h>
char a[2][200];
int main()
{
	int n,i,j,k;
	
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	scanf("%c",&a[0][i]);
	getchar();
	for(i=0;i<n;i++)
	scanf("%c",&a[1][i]);
	//puts(a[0]);
	//puts(a[1]);
	for(i=0;i<n;i++)
	{
		if(a[0][i]==a[1][0])
		{
			for(j=i,k=0;j<n;j++,k++)
			{
				if(a[0][j]!=a[1][k])
				{
					break;
					j--;
				}
			}
			if(j==n)
			{
				printf("%d\n",n+(n-k));
				return 0;
		    }
	    } 
    }
	if(i==n)
	printf("%d\n",n*2); 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&a[0][i]);
  ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&a[1][i]);
  ^