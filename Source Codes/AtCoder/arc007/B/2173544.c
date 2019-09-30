#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	int ca[105];
	for(i=1;i<=n;i++)
		ca[i]=i;
	int pl=0;
	int di;
	int x;
	for(i=0;i<m;i++)
	{
		scanf("%d",&di);
		if(di!=pl)
		{
			j=1;
			while(ca[j]!=di)
				j++;
			x=pl;
			pl=di;
			ca[j]=x;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d\n",ca[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&di);
   ^