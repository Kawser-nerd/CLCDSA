#include<stdio.h>
#include<math.h>

struct p_t
{
	double time,dist;
};

double d;
int n,a;
struct p_t pos[3000];

char feasible(double wait, double accel)
{
	int i;
	double us,him,time;

	//printf("-- wait:%.7f accel:%.7f\n",wait,accel);
	for (i=0;i<n;i++)
	{
		time=pos[i].time-wait;
		if (time<0.0) { continue; }
		us=time*time*accel*0.5;
		him=pos[i].dist;
		//printf("    %.7f < %.7f = %d\n",him,us,(int)(him<us));
		if (him<us) { return 0; }
	}
	return 1;
}

int main()
{
	int t,tt;
	int i;
	double left,right,mid,accel;
	char ret;

	scanf("%d",&tt);
	for (t=1;t<=tt;t++)
	{
		scanf("%lf %d %d",&d,&n,&a);
		for (i=0;i<n;i++) { scanf("%lf %lf",&pos[i].time,&pos[i].dist); }

		for (i=0;i<n;i++)
		{
			if (i==0 && pos[i].dist>d)
			{
				pos[i].time=pos[i].time*d/pos[i].dist;
				pos[i].dist=d;
				n=1;
				break;
			}
			if (i>0 && pos[i].dist>d)
			{
				pos[i].time=(pos[i].time-pos[i-1].time)*(d-pos[i-1].dist)/(pos[i].dist-pos[i-1].dist) + pos[i-1].time;
				pos[i].dist=d;
				n=i+1;
				break;
			}
		}
		//printf("--> %.7f %.7f\n",pos[n-1].time,pos[n-1].dist);

		printf("Case #%d:\n",t);
		for (i=0;i<a;i++)
		{
			scanf("%lf",&accel);
			left=0; right=pos[n-1].time;
			//printf(" < %.7f - %.7f >\n",left,right);
			mid=(left+right)/2.0;
			while (left<=right && right-left>1e-9)
			{
				mid=(left+right)/2.0;
				ret=feasible(mid,accel);
				//printf("%.7f = %hhd\n",mid,ret);
				if (ret) { right=mid; } else { left=mid; }
			}
			printf("%.8f\n",mid+sqrt(2*d/accel));
		}
	}

	return 0;
}

