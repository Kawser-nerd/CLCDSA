#include<stdio.h>
#include<math.h>

int main()
{
	int t,n;
	int vx[500],vy[500],vz[500],x[500],y[500],z[500];
	int i,j;
	int sumx,sumy,sumz,vsumx,vsumy,vsumz;
	long double ans,d;
	long double k,l;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		
		sumx=0;
		sumy=0;sumz=0;vsumx=0;vsumy=0;vsumz=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d%d%d%d%d%d",&x[j],&y[j],&z[j],&vx[j],&vy[j],&vz[j]);
			sumx+=x[j];
			sumy+=y[j];
			sumz+=z[j];
			vsumx+=vx[j];
			vsumy+=vy[j];
			vsumz+=vz[j];
		}
		k=sumx*vsumx+sumy*vsumy+sumz*vsumz;
		l=vsumx*vsumx+vsumy*vsumy+vsumz*vsumz;
//		printf("%do_O%d___",sumx,vsumx);
		if(l==0)
			ans = 0;
		else
			ans=k/l;
		ans=-1*ans;
		if(ans<=0)
			ans=0;
		d=pow((sumx+vsumx*ans),2)+pow((sumy+vsumy*ans),2)+pow((sumz+vsumz*ans),2);
//		printf("%f",d);
		d=sqrt(d);
		d=d/(long double)n;
		printf("Case #%d: %.8Lf %.8Lf\n",i,d,ans);
	}
}

