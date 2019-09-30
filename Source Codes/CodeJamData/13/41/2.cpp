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
#include <cassert>

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

#define FN "A-large"
#define MOD 1000002013

LL n,m;

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		printf("Case #%d: ",test);
		cin >> n >> m;
		map<int,LL> a;
		LL real = 0;
		REP(i,m)
		{
			int x,y,k;
			cin >> x >> y >> k;
			a[x] += k;
			a[y] -= k;
			LL q = (2LL*n+1-(y-x))*(LL)(y-x)/2;
			q%=MOD;
			q*=k;
			q%=MOD;
			real = (real+q)%MOD;
		}
		vector<pair<int,LL>> b;
		LL res = 0;
		for (map<int,LL>::iterator it = a.begin(); it != a.end(); ++it)
		{
			if (it->second > 0)
			{
				b.push_back(*it);
			}
			else if (it->second < 0)
			{
				LL left = -it->second;
				while (left)
				{
					LL amount = min(left, min(100000000LL, b.back().second));
					b.back().second -= amount;
					left -= amount;
					LL k = it->first - b.back().first;
					LL q = (2LL*n+1-k)*k/2;
					q%=MOD;
					q*=amount;
					q%=MOD;
					res = (res+q)%MOD;
					if (b.back().second == 0) b.pop_back();
				}
			}
		}
		res = (real+MOD-res)%MOD;
		printf("%d\n",(int)(res%MOD));
	}
	return 0;
}