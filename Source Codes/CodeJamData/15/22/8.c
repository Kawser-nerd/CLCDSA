#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int minx,r,c,n,a[20][20];
void dfs(int x,int y)
{
  int f,t,i,j,nx,ny;
  if (x>r)
  {
	f=t=0;
	for (i=1;i<=r;i++)
	  for (j=1;j<=c;j++)
		if (a[i][j])
	  {
		t++;
		if (a[i+1][j]) f++;
		if (a[i][j+1]) f++;
	  }
	if (t==n) minx=min(minx,f);
	return;
  }
  if (y==c) nx=x+1,ny=1;
  else nx=x,ny=y+1;
  a[x][y]=0;
  dfs(nx,ny);
  a[x][y]=1;
  dfs(nx,ny);
}
int main()
{
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  int t,T;
  scanf("%d",&T);
  for (t=1;t<=T;t++)
  {
	memset(a,0,sizeof(a));
	scanf("%d%d%d",&r,&c,&n);
	minx=0x3f3f3f3f;
	dfs(1,1);
	printf("Case #%d: %d\n",t,minx);
  }
  return 0;
}
