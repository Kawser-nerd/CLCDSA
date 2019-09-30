#include<stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	int a[101];
	int sum = 0;
	for(i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int m,j;
	int x;
	int y,number;
	scanf("%d",&m);
	int t;
	for(j = 0;j<m;j++)
	{
		t = sum;
		scanf("%d%d",&x,&y);
		t -= a[x-1];
		t += y;
		printf("%d\n",t);
	}
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^