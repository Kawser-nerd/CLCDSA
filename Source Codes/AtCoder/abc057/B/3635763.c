#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	int a[55],b[55],c[55],d[55];
	for(i=0;i<n;i++)
	  scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<m;i++)
	  scanf("%d %d",&c[i],&d[i]);
	int min,ans;
	int x;
	for(i=0;i<n;i++)
	{
		min=abs(a[i]-c[0])+abs(b[i]-d[0]);
		ans=1;
		for(j=1;j<m;j++)
		{
			x=abs(a[i]-c[j])+abs(b[i]-d[j]);
			if(min>x)
			{
				min=x;
				ans=j+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:7: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   min=abs(a[i]-c[0])+abs(b[i]-d[0]);
       ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&a[i],&b[i]);
    ^
./Main.c:12:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&c[i],&d[i]);
    ^