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
#define INF 0x1fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define NAME "D-large"

int k,m,n;
char buf[64000];
int a[32][32];
int d[1<<16][16][16];

int bitcnt(int x)
{
	int res=0;
	for (; x!=0; x&=x-1)
		res++;
	return res;
}

void gamilton()
{
	FILL(d,-1);
	REP(i,1<<k) REP(i1,k) REP(i2,k)
		d[i][i1][i2]=INF;
	REP(i,k)
		d[1<<i][i][i]=0;
	VI masks[17];
	REP(i,k) masks[i].clear();
	REP(i,1<<k) masks[bitcnt(i)].push_back(i);
	for (int cnt=1; cnt < k; cnt++)
		REP(i,SZ(masks[cnt]))
		{
			int msk=masks[cnt][i];
			REP(st,k) if ((msk&(1<<st))!=0)
				REP(fn,k) if ((msk&(1<<fn))!=0)
					REP(j,k) if ((msk&(1<<j))==0)
						d[msk | (1<<j)][st][j] = min(d[msk | (1<<j)][st][j], d[msk][st][fn] + a[fn][j]);
		}
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		scanf("%d",&k);
		gets(buf); gets(buf);
		m=strlen(buf);
		/*REP(i,k)
			buf[m+i]='#';
		m+=k;*/
		CLEAR(a);
		n=m/k;
		REP(i,k) REP(j,i)
		{
			for (int ii = 0; ii < m; ii+=k)
				if (buf[ii+i] != buf[ii+j])
					a[i][j]++;
			a[j][i]=a[i][j];
		}
		gamilton();
		int res=INF;
		REP(st,k) REP(fn,k) if (st!=fn)
		{
			int cur = d[(1<<k)-1][st][fn]+1;
			for (int ii = k; ii < m; ii+=k)
				if (buf[ii-k+fn] != buf[ii+st])
					cur++;
			res=min(res,cur);
		}

		printf("Case #%d: %d\n",tst+1,res);
	}
	return 0;
}
