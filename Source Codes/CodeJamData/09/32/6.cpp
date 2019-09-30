#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define UN(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b) memset(a,b,sizeof a)
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int h=1000;
int tt,n, x,y,z,vx,vy,vz, xx,yy,zz,xv,yv,zv;
ll a,b,c;
double d, t, t1,t2;

double sqr(double x) { return x*x; }

int main()
{
freopen("b-large.in", "r", stdin);
freopen("b-large.out", "w", stdout);
	scanf("%d", &tt);
	REP(it, tt)
	{
		scanf("%d", &n);
		xx=yy=zz=xv=yv=zv=0;
		REP(i, n)
		{
			scanf("%d%d%d%d%d%d", &x, &y, &z, &vx, &vy, &vz);
			xx+=x; yy+=y; zz+=z;
			xv+=vx; yv+=vy; zv+=vz;
		}
		a=ll(xv)*xv+ll(yv)*yv+ll(zv)*zv;
		b=ll(xx)*xv+ll(yy)*yv+ll(zz)*zv;
		c=ll(xx)*xx+ll(yy)*yy+ll(zz)*zz;
//		cout<<a<<' '<<b<<' '<<c<<'\n';
		if(a==0)
		{
			if(b==0) t=0;
			else t=max(0.0, -double(c)/b/2);
		}
		else
		{
			d=double(b)*b-double(a)*c;
			if(d<0) t=max(0.0, -double(b)/a);
			else
			{
				t1=(-b-sqrt(d))/a;
				t2=(-b+sqrt(d))/a;
				if(t1<0) t=max(0.0, t2);
				else t=t1;
			}
		}
		d=sqrt(sqr(xx+xv*t)+sqr(yy+yv*t)+sqr(zz+zv*t))/n;
		printf("Case #%d: %.8lf %.8lf\n", it+1, d, t);
	}
	return 0;
}
