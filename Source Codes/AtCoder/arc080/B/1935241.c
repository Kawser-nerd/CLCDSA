#include <stdio.h>
int main(void)
{
	int h,w,n,i,j=0,x=0,t=1;
	scanf("%d %d",&h,&w);
	scanf("%d",&n);
	int a[10000],b[100][100],c[10000],y=w-1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		while(a[i]>0)
		{
			c[j++]=i;
			a[i]--;
		}
	}
	b[0][w-1]=1;
	while(t<j)
	{
		while(x+1<h&&!b[x+1][y]) 
		{
			b[++x][y]=c[t];
			t++;
		}
        while(y-1>=0&&!b[x][y-1]) 
		{
			b[x][--y]=c[t];
			t++;
		}
        while(x-1>=0&&!b[x-1][y]) 
		{
			b[--x][y]=c[t];
			t++;
		}
        while(y+1<w&&!b[x][y+1])  
		{
			b[x][++y] =c[t];
			t++;
		}
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
	      printf("%d ",b[i][j]);
	    printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^