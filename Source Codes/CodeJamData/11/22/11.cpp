#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i=(a), _b=(b); i>=_b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define INF 1000000000
#define INF_LL 1000000000000000000LL
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int h = 222;

int c, d, p[h], v[h];
vi a;

int main()
{
	freopen("b-large.in", "r", stdin); //-small-attempt
	freopen("b-large.out", "w", stdout); //-large
	int T, it=1;
for(scanf("%d", &T); it<=T; ++it)
{
	scanf("%d%d", &c, &d);
	d *= 2;
	REP(i, c) scanf("%d%d", p+i, v+i), p[i] *= 2;
	a.clear();
	REP(i, c) REP(j, v[i]) a.pb(p[i]);
	sort(all(a));
	int n = sz(a);
	ll l=-1, r=INF_LL, t;
	while(r-l > 1)
	{
		t = (l+r) / 2;
		ll x = -INF_LL;
		bool ok = true;
		REP(i, n)
		{
			x += d;
			//cout<<i<<' '<<x<<' '<<a[i]+t<<endl;
			if(a[i]+t < x)
			{
				ok = false;
				break;
			}
			x = max(x, a[i]-t);
		}
		if(ok) r = t;
		else l = t;
	}
	printf("Case #%d: %I64d", it, r/2);
	if(r&1) printf(".5");
	printf("\n");
}
	return 0;
}
