#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int H,W,h,w;
int mat[550][550];
long long sum;
int main()
{
	scanf("%d%d%d%d",&H,&W,&h,&w);
	for(int i=h;i<=H;i+=h)
		for(int j=w;j<=W;j+=w)
			mat[i][j]=-4000*h*w+3999;
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			if(!mat[i][j])sum+=4000;
			else sum+=mat[i][j];
	if(sum<=0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
		{
			if(!mat[i][j])printf("4000 ");
			else
				printf("%d ",mat[i][j]);
			if(j==W)puts("");
		}
	return 0;
}