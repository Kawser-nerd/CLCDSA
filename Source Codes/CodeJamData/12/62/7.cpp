#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "B-large"

template<class T> inline T gcd(T a,T b) {
	if(a<0)a=-a; if(b<0)b=-b; if(a<b)swap(a,b);
	while (b) {T t = b; b=a%b; a=t;} return a; }

struct Fr{LL a,b;
	Fr::Fr(LL a=0,LL b=1){LL d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
	string toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();} };
Fr operator+(Fr p,Fr q){return Fr(p.a*q.b+q.a*p.b,p.b*q.b);}
Fr operator-(Fr p,Fr q){return Fr(p.a*q.b-q.a*p.b,p.b*q.b);}
Fr operator*(Fr p,Fr q){return Fr(p.a*q.a,p.b*q.b);}
Fr operator/(Fr p,Fr q){return Fr(p.a*q.b,p.b*q.a);}
bool operator<(Fr p,Fr q){return p.a*q.b<q.a*p.b;}
bool operator==(Fr p,Fr q){return p.a*q.b==q.a*p.b;}
bool operator!=(Fr p,Fr q){return p.a*q.b!=q.a*p.b;}
bool operator<=(Fr p,Fr q){return p.a*q.b<=q.a*p.b;}

#define N 1024000
int n,kk;
pair<Fr,int> a[N];
double aa[N],pp[N],bb[N],qq[N];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d%d",&n,&kk);
		REP(i,n)
		{
			int x,y,c;
			scanf("%d/%d %d",&x,&y,&c);
			a[i] = make_pair(Fr(x,y),c);
		}
		sort(a,a+n);
		reverse(a,a+n);
		int x;
		x = 0;
		aa[0] = 1.0;
		pp[0] = 1.0;
		REP(i,n) REP(j,a[i].second)
		{
			++x;
			double p = a[i].first.a / (double)a[i].first.b;
			pp[x] = pp[x-1]*p;
			aa[x] = aa[x-1]*(1-p) + pp[x];
		}
		x = 0;
		bb[0] = 1.0;
		qq[0] = 1.0;
		REPD(i,n) REP(j,a[i].second)
		{
			++x;
			double p = a[i].first.a / (double)a[i].first.b;
			qq[x] = qq[x-1]*(1-p);
			bb[x] = bb[x-1]*p + qq[x];
		}
		double res = 0;
		FOR(x,0,kk)
		{
			int y = kk-x;
			res = max(res, aa[x]*qq[y]+pp[x]*bb[y]-pp[x]*qq[y]);
		}
		printf("Case #%d: %.12lf\n",test,1.0-res);
	}
	return 0;
}