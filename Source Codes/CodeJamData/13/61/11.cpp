/*
All the clever ideas, bugs and features of this solution are dedicated to
my little hobbit, Terka, who always makes me smile.
*/
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

const int MAX = 1000;
ll N, X;
int C;

struct rec
{
	ll s, e, t, d;

	ll pos(int T)
	{
		if (T < t || T > t+d) return -1;
		return (s+T-t) % N;
	}
} in[MAX];

void Solve(int tc)
{
	cin >> C >> X >> N;
	REP(i, C)
	{
		cin >> in[i].s >> in[i].e >> in[i].t;
		--in[i].s;
		--in[i].e;
		in[i].d = in[i].e - in[i].s;
		if (in[i].d < 0) in[i].d += N;
	}

	ll res = 0;
	REP(i, N)
	{
		REP(t, X)
		{
			int n = i;
			for (int step = 0; t+step <= X; ++step)
			{
				bool ok = true;
				REP(c, C)
				{
					ll pos = in[c].pos(t+step);
					if (pos == -1) continue;
					if (pos == n || (step && in[c].pos(t+step-1) == n))
						ok = false;
				}

				if (!ok) break;
				n = (n-1+N) % N;
				res = max(res, (ll)step);
			}
		}
	}
	printf("Case #%d: %lld\n", tc, res);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}