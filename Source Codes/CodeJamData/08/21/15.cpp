#include <algorithm>
#include <string>
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

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

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

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define NAME "A-large"

LL a[9];

void add(LL x, LL y)
{
	a[(x%3)*3+(y%3)]++;
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		int n,A,B,C,D,x0,y0,M;
		scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&D,&x0,&y0,&M);
		CLEAR(a);
		add(x0,y0);
		LL X=x0,Y=y0;
		REP(i,n-1)
		{
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			add(X,Y);
		}
		LL res=0;
		REP(p1,9) REP(p2,p1+1) REP(p3,p2+1)
			if ((((p1%3)+(p2%3)+(p3%3))%3) == 0 && (((p1/3)+(p2/3)+(p3/3))%3) == 0)
			{
				map<int,int> mm;
				mm.clear();
				mm[p1]++;
				mm[p2]++;
				mm[p3]++;
				LL cur=1;
				for (map<int,int>::iterator it=mm.begin(); it!=mm.end(); it++)
					if (it->second == 1)
						cur*=a[it->first];
					else if (it->second == 2)
						cur*=a[it->first]*(a[it->first]-1)/2;
					else if (it->second == 3)
						cur*=a[it->first]*(a[it->first]-1)*(a[it->first]-2)/6;
				res+=cur;
			}
		printf("Case #%d: %lld\n",tst+1,res);
	}
	return 0;
}
