#include <stdio.h>
#include <math.h>

int main()
{
	int x[500];
	int y[500];
	int z[500];
	int vx[500];
	int vy[500];
	int vz[500];
	int t;
	scanf("%d",&t);
	int ti;
	for (ti=1;ti<=t;ti++)
	{
		int n;
		scanf("%d",&n);
		int ni;
		double sx=0,sy=0,sz=0,svx=0,svy=0,svz=0;
		for (ni=0;ni<n;ni++)
		{
			scanf("%d %d %d %d %d %d",&x[ni],&y[ni],&z[ni],&vx[ni],&vy[ni],&vz[ni]);
			sx+=x[ni];
			sy+=y[ni];
			sz+=z[ni];
			svx+=vx[ni];
			svy+=vy[ni];
			svz+=vz[ni];
		}
		sx/=n;
		sy/=n;
		sz/=n;
		svx/=n;
		svy/=n;
		svz/=n;
		double tt;
		if (svx*svx+svy*svy+svz*svz==0)
			tt=0;
		else
			tt=-(sx*svx+sy*svy+sz*svz)/(svx*svx+svy*svy+svz*svz);
		if (tt<0) tt=0;
		double dx=sx+tt*svx;
		double dy=sy+tt*svy;
		double dz=sz+tt*svz;
		double d=sqrt(dx*dx+dy*dy+dz*dz);
		printf("Case #%d: %lf %lf\n",ti,d,tt);
	}
	return 0;
}
