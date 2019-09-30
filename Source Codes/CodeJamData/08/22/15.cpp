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

#define NAME "B-large"

#define MAX 1222000
bool ispr[MAX+1000];
int prc;
LL pr[MAX],A,B,P;
int n;
VI a[MAX];
bool mark[MAX];

void addedge(int x, int y)
{
	a[x].push_back(y);
	a[y].push_back(x);
}

void dfs(int v)
{
	mark[v]=true;
	REP(i,SZ(a[v]))
		if (!mark[a[v][i]])
			dfs(a[v][i]);
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	CLEAR(ispr);
	prc=0;
	for (int i = 2; i < MAX; i++)
		if (!ispr[i])
		{
			pr[prc++] = i;
			for (int j = 2*i; j < MAX; j+=i)
				ispr[j]=true;
		}
	//fprintf(stderr,"%d\n",prc);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		scanf("%lld%lld%lld",&A,&B,&P);
		n=B-A+1;
		REP(i,n)
			a[i].clear();
		REP(i,prc)
			if (pr[i] >= P && pr[i] <= n)
			{
				LL d = pr[i];
				LL x = (A/d)*d;
				if (x < A) x+=d;
				if (x > B) continue;
				int ix = (int)(x-A);
				for (LL iy = ix+d; iy < n; iy+=d)
					addedge(ix,iy);
			}
		/*for (LL x = A; x <= B; x++)
		{
			if ((x%10000)==0)
				fprintf(stderr,"=");
			vector<LL> qq;
			qq.clear();
			LL xx=x;
			for (int i = 0; i < prc && pr[i]*pr[i] <= xx; i++)
				if ((xx%pr[i])==0)
				{
					qq.push_back(pr[i]);
					while ((xx%pr[i])==0)
						xx/=pr[i];
				}
			if (xx>1)
				qq.push_back(xx);
			int ix = (int)(x-A);
			REP(i,SZ(qq)) if (qq[i]>=P)
				for (LL iy = ix+qq[i]; iy < n; iy+=qq[i])
					addedge(ix,iy);
		}*/
		int res=0;
		CLEAR(mark);
		fprintf(stderr,"***\n");
		REP(i,n)
			if (!mark[i])
			{
				dfs(i);
				res++;
			}
		printf("Case #%d: %d\n",tst+1,res);
	}
	return 0;
}
