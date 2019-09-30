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

#define N 1024
int n;
int a[N],b[N];
int lvl[N];

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d",&n);
		REP(i,n) scanf("%d%d",&a[i],&b[i]);
		CLEAR(lvl);
		int sum = 0;
		int iter = 0;
		while (sum < 2*n)
		{
			++iter;
			REP(i,n)
			{
				if (lvl[i]<2 && b[i]<=sum)
				{
					sum+=2-lvl[i];
					lvl[i]=2;
					goto end;
				}
			}
			int best = -1;
			REP(i,n)
			{
				if (lvl[i]==0 && a[i]<=sum)
					if (best == -1 || b[i] > b[best])
						best = i;
			}
			if (best == -1) break;
			lvl[best]=1;
			++sum;
			end:;
		}
		printf("Case #%d: ",test);
		if (sum == 2*n)
			printf("%d\n",iter);
		else
			printf("Too Bad\n");
	}
	return 0;
}