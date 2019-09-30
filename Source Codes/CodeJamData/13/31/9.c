#include<stdio.h>
#include<string.h>
int w,h,i,n,sp,t,x,j,v,m,a[2000][200],f[2000][200],q[2000][200];
void zy()
{
	int r;
	if (j<3)
		for (r=0;r<j+3;r++)
		if (f[i+1][r]>f[i][j])
		{
			f[i+1][j]=f[i][r];
			q[i+1][j]=r;	
		}
	if (j>w)
		for (r=0;r<j+3;r++)
		if (f[i-1][r]>f[i][j])
		{
			f[i][j]=f[i-1][r];
			q[i][j]=r;	
		}
}

int main()
{
	scanf("%d %d",&w,&h);
	m=0;
	while (scanf("%d %d %d %d",&t,&x,&sp,&v) != EOF)
	{
		if (h % sp==0) 
		{
			t=t+h/sp;
			if (t > m) m=t;
			a[t][x]=a[t][x]+v;
		}
	}
	for (i=0;i<=m-1;i++)
	{
		for (j=1;j<=w;j++)
		zy;
	}
	return 0;
}
