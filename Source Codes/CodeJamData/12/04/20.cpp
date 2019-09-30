#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <assert.h>

#pragma warning(disable:4996)

#define TIME fprintf(stderr,"\n-----------\ntime : %.2f sec\n",double(clock())/CLOCKS_PER_SEC);
#define EXIT exit(0);
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("output.txt","w",stdout);
#define DOUT(_X) fprintf(stderr,"%d ",_X);
#define DLINE fprintf(stderr,"\n");

#define M 0
#define MOD 0
#define ADD(_X,_Y) _X=(_X+_Y)%MOD;

#define abs(_Z) (((_Z)<0)?-(_Z):(_Z))
#define f0(_X,_Y) for(_X=0;_X<_Y;++_X)
#define f1(_X,_Y) for(_X=1;_X<=_Y;++_X)
#define ff(_X,_Y,_Z) for(_X=_Y;_X<=_Z;++_X)
#define fF(_X,_Y,_Z) for(_X=_Y;_X<_Z;++_X)
#define pb push_back
#define sz(_X) _X.size()
typedef long long ll;

int H,W,D,startX,startY;
char a[33][33];
const int DY[]={1,-1,1,-1},DX[]={1,1,-1,-1};

int process(int vy,int vx)
{
	int i,dx=0,dy=0,enable[4],ans=0,cx,cy;
	int flipX[4],flipY[4],buf,x[4],y[4];

	f0(i,4) x[i]=startX, y[i]=startY, flipX[i]=flipY[i]=1, enable[i]=true;
	if(vy==0) enable[1]=enable[3]=false;
	if(vx==0) enable[2]=enable[3]=false;

	while(dx*dx+dy*dy<=D*D)
	{
		buf=(2*dx+1)*vy-(2*dy+1)*vx; // < int
		if(buf<0) // goes X
		{
			++dx;
			f0(i,4) if(enable[i])
			{
				x[i]+=DX[i]*flipX[i];
				if(a[y[i]][x[i]]=='#')
				{
					x[i]-=DX[i]*flipX[i];
					flipX[i]*=-1;
				}
				if(a[y[i]][x[i]]=='X')
					// passing exactly center?
					if(dx*vy==dy*vx)
					{
						if(dx*dx+dy*dy<=D*D){++ans; }
						enable[i]=false;
					}
			}
		}
		else if(buf>0)
		{
			++dy;
			f0(i,4) if(enable[i])
			{
				y[i]+=DY[i]*flipY[i];
				if(a[y[i]][x[i]]=='#')
				{
					y[i]-=DY[i]*flipY[i];
					flipY[i]*=-1;
				}
				if(a[y[i]][x[i]]=='X')
					// passing exactly center?
					if(dx*vy==dy*vx)
					{
						if(dx*dx+dy*dy<=D*D){ ++ans; }
						enable[i]=false;
					}
			}
		}
		else
		{
			++dx;
			++dy;
			f0(i,4) if(enable[i])
			{
				// blocked?
				x[i]+=DX[i]*flipX[i];
				y[i]+=DY[i]*flipY[i];
				if(a[y[i]][x[i]]=='#') // corner
				{
					cx=a[y[i]][x[i]-DX[i]*flipX[i]]=='#';
					cy=a[y[i]-DY[i]*flipY[i]][x[i]]=='#';
					if(cx) y[i]-=DY[i]*flipY[i], flipY[i]*=-1;
					if(cy) x[i]-=DX[i]*flipX[i], flipX[i]*=-1;

					if(!cx && !cy) enable[i]=false;
				}
				if(a[y[i]][x[i]]=='X' && enable[i])
					// passing exactly center?
					if(dx*vy==dy*vx)
					{
						if(dx*dx+dy*dy<=D*D) ++ans;
						enable[i]=false;
					}
			}
		}
	}
	return ans;
}

int main()
{
	int t,T,ans,x,y,z,i,j;

	FIN
	FOUT

	scanf("%d",&t);
	f1(T,t)
	{
		scanf("%d%d%d",&H,&W,&D);
		f1(i,H)
		{
			scanf("%s",a[i]+1);
			f1(j,W) if(a[i][j]=='X') startY=i, startX=j;
		}

		ans=process(0,1)+process(1,0);
		f1(i,D) f1(j,D) if(i*i+j*j<=D*D)
		{
			x=i;
			y=j;
			while(y)
			{
				z=x%y;
				x=y;
				y=z;
			}
			if(x==1) ans+=process(i,j);
		}


		printf("Case #%d: %d\n",T,ans);
	}

	return 0;
}
