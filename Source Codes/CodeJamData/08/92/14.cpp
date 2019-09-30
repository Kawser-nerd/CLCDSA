#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<set>
#include<vector>
#include<list>
#include<queue>

using namespace std;

const int inf = 2147483647;
const double eps = 1e-7;

template<class T> T abs(T x) {return x>0?x:-x;}
template<class T> string toString(T x) {string ret; stringstream sin; sin<<x; sin>>ret; return ret;}

int N,M,A,B,C,D,X,Y;
/*
int len(int x,int y,int C,int D)
{
	int tmp;
	if(x<0)
	{
		if(C<=0) return 0;
		else if(C>0)
		{
			tmp = -x/C;
			x += C * tmp; y += D * tmp;
			while(x<0)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(x>=N)
	{
		if(C>=0) return 0;
		else if(C<0)
		{
			tmp = -(x-N+1)/C;
			x += C * tmp; y += D * tmp;
			while(x>=N)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(y<0)
	{
		if(D<=0) return 0;
		else if(D>0)
		{
			tmp = -y/D;
			x += C * tmp; y += D * tmp;
			while(y<0)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(y>=M)
	{
		if(D>=0) return 0;
		else if(D<0)
		{
			tmp = -(y-N+1)/D;
			x += C * tmp; y += D * tmp;
			while(y>=M)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(x<0)
	{
		if(C<=0) return 0;
		else if(C>0)
		{
			tmp = -x/C;
			x += C * tmp; y += D * tmp;
			while(x<0)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(x>=N)
	{
		if(C>=0) return 0;
		else if(C<0)
		{
			tmp = -(x-N+1)/C;
			x += C * tmp; y += D * tmp;
			while(x>=N)
			{
				x+=C;
				y+=D;
			}
		}
	}
	if(x<0 || x>=N || y<0 || y>=M) return 0;
	int ans = N + M;
	if(C<0) ans=min(ans,-x/C);
	else if(C>0) ans=min(ans,(N-x-1)/C);
	if(D<0) ans=min(ans,-y/D);
	else if(D>0) ans=min(ans,(M-y-1)/D);
	return ans + 1;
}*/

int qx[100000],qy[100000],l,r;
int vis[200][200];

int calc(int x,int y)
{/*
	int ret = 0;
	for(int i=0;i<=N+M;i++)
	{
		ret += len(x,y,C,D);
		x += A; y += B;
	}
	return ret;*/
	memset(vis,0,sizeof(vis)); l = r = 0;
	qx[r] = x; qy[r] = y; r++; vis[x][y] = true;
	while(l<r)
	{
		int X = qx[l], Y = qy[l]; l++;
		int XX,YY;
		XX = X + A; YY = Y + B;
		if(XX>=0 && XX<N && YY>=0 && YY<M && !vis[XX][YY])
		{
			vis[XX][YY] = true;
			qx[r] = XX;
			qy[r] = YY;
			r++;
		}
		XX = X + C; YY = Y + D;
		if(XX>=0 && XX<N && YY>=0 && YY<M && !vis[XX][YY])
		{
			vis[XX][YY] = true;
			qx[r] = XX;
			qy[r] = YY;
			r++;
		}
	}
	return r;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B2.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test = 1; test<=ntest; test++)
	{
		scanf("%d%d",&N,&M);
		scanf("%d%d%d%d",&A,&B,&C,&D);
		scanf("%d%d",&X,&Y);
		int ans = calc(X,Y);
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}
