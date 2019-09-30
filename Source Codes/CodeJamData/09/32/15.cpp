#include <cstdio>
#include <cmath>

#define N 505

typedef long long ll;

int t,test;
int n,i;
int x,y,z,vx,vy,vz;
int sx,sy,sz,svx,svy,svz;
ll a,b,c;
double dmin,tmin;

inline int sign(ll x)
{
	if(x>0)return 1;else
	if(x<0)return -1;else
		return 0;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&test);
	for(t=1;t<=test;t++)
	{
		scanf("%d",&n);
		sx=sy=sz=svx=svy=svz=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d%d",&x,&y,&z,&vx,&vy,&vz);
			sx+=x;
			sy+=y;
			sz+=z;
			svx+=vx;
			svy+=vy;
			svz+=vz;
		}
		a=(ll)svx*svx+(ll)svy*svy+(ll)svz*svz;
		b=2*((ll)sx*svx+(ll)sy*svy+(ll)sz*svz);
		c=(ll)sx*sx+(ll)sy*sy+(ll)sz*sz;
		if(a==0)
		{
			tmin=0;
			dmin=sqrt((double)c)/n;
		}else
		if(sign(b)*sign(a)<=0)
		{
			tmin=-((double)b)/(2*a);
			dmin=sqrt(c-(double)b*b/(4*a))/n;
		}else
		{
			tmin=0;
			dmin=sqrt((double)c)/n;
		}
		printf("Case #%d: %.9lf %.9lf\n",t,dmin,tmin);
	}
	return 0;
}
