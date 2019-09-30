#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 1000000 + 10;
const long double zero = 1e-9;

pair<long double,long double> p[maxn];
long double x[maxn],y[maxn];
long double ans;
int n;

void init()
{
	long double si = 1.0*(rand()+1) / 100000;
	long double co = sqrt(1-si*si);

	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		p[i].first = x*co - y*si;
		p[i].second = x*si + y*co;
	}
	sort( p,p+n );
}
inline long double sqr( double x )
{
	return x*x;
}
inline long double dist( int a,int b )
{
	return sqrt( sqr(x[a]-x[b])+sqr(y[a]-y[b]) );
}
int q[maxn],top;
long double dd[maxn];
inline bool cmp( const int a,const int b )
{
	return y[a] + zero < y[b];
}
void work( int l,int r )
{
	if( r-l+1 <= 5 )
	{
		for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
		for(int k=j+1;k<=r;k++) ans = min(ans,dist(i,j)+dist(i,k)+dist(j,k));
	}else
	{
		int mid = (l+r)>>1;
		work(l,mid);
		work(mid+1,r);

		for(int i=l;i<=mid;i++)
		{
			top = 0;
			for(int j=mid+1;j<=r;j++) if( x[j]-x[i] +zero< 0.5*ans )
			{
				if( dist(i,j) +zero< 0.5*ans ) q[top++] = j;
			}else break;
			sort( q,q+top,cmp );

			for(int j=0;j<top;j++) dd[j] = dist(i,q[j]);

			for(int j=0;j<top;j++)
			for(int k=j+1;k<top;k++) if( y[q[k]]-y[q[j]] +zero< 0.5*ans )
			{
				ans = min( ans,dd[j]+dd[k]+dist(q[j],q[k]) );
			}else break;
		}


		for(int i=mid+1;i<=r;i++)
		{
			top = 0;
			for(int j=mid;j>=l;j--) if( x[i]-x[j] +zero< 0.5*ans )
			{
				if( dist(i,j) +zero< 0.5*ans ) q[top++] = j;
			}else break;
			sort( q,q+top,cmp );

			for(int j=0;j<top;j++) dd[j] = dist(i,q[j]);

			for(int j=0;j<top;j++)
			for(int k=j+1;k<top;k++) if( y[q[k]]-y[q[j]] +zero< 0.5*ans )
			{
				ans = min( ans,dd[j]+dd[k]+dist(q[j],q[k]) );
			}else break;
		}

	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for( int num=1;num<=T;num++ )
	{
		printf("Case #%d: ",num );
		init();
		ans = 1e100;
		for(int i=0;i<n;i++)
		{
			x[i] = p[i].first;
			y[i] = p[i].second;
		}
		work(0,n-1);
		printf("%.15lf\n",(double)ans);
	}
	return 0;
}
