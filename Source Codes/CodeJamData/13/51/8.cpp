#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 40;
int N;
ll B;
vector<ll> in;

ll need(int winning, ll bet)
{
	ll res = 0;
	REP(i, 37)
		if (i < winning)
			res += bet-in[i];
		else
			res += max(0LL, bet+1-in[i]);
	return res;
}

void Solve(int tc)
{
	cin >> B >> N;
	in = vector<ll>(37, 0);
	REP(i, N) cin >> in[i];
	sort(in.begin(), in.end());

	double res = 0.0;
	FOR(winning, 1, 37)
	{
		FOR(raise, 0, 37-winning)
		{
			ll be = in[winning-1], en = winning+raise==37?B:in[winning+raise]-1, val = -1;
			while (be <= en)
			{
				ll m = (be + en) / 2;
				ll n = need(winning, m);
				if (n <= B)
				{
					val = m;
					be = m+1;
				}
				else
					en = m-1;
			}
			if (val != -1)
			{
				double act = 0.0;
				REP(i, winning)
					act += val - in[i];
				res = max(res, act*36.0/winning - need(winning, val));
			}
		}
	}

	printf("Case #%d: %.12lf\n", tc, res);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}