#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=100;
double x[maxn],y[maxn],r[maxn];
int n,t,cases;

double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double calc()
{
	if (n==1) return r[0];
	if (n==2) return max(r[1],r[0]);
	double res=1e100;
	res=min(res,max(r[0],(dist(x[1],y[1],x[2],y[2])+r[1]+r[2])/2.0));
	res=min(res,max(r[1],(dist(x[0],y[0],x[2],y[2])+r[0]+r[2])/2.0));
	res=min(res,max(r[2],(dist(x[1],y[1],x[0],y[0])+r[1]+r[0])/2.0));
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);

	for (scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		printf("Case #%d: %0.9lf\n",++cases,calc());
	}
}