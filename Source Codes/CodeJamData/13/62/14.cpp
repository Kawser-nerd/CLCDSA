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

const int MAX = 50007;
int N, in[MAX];

bool check(double e)
{
	REP(i, N)
	{
		double be = 0.0, en = 1e9, x = in[i] - e;
		REP(j, i)
		{
			en = min(en, (x-in[j]+e) / (i-j));
			be = max(be, (x-in[j]-e) / (i-j));
		}
		FOR(j, i+1, N-1)
		{
			en = min(en, (in[j]+e-x) / (j-i));
			be = max(be, (in[j]-e-x) / (j-i));
		}
		if (be-1e-9 <= en)
			return true;
	}
	return false;
}

void Solve(int tc)
{
	scanf("%d", &N);
	REP(i, N) scanf("%d", &in[i]);
	printf("Case #%d: ", tc);

	if (N <= 2) { printf("0\n"); return; }

	double be = 0.0, en = 1e9;
	REP(step, 100)
	{
		double m = (be+en) / 2.0;
		if (check(m)) en = m;
		else be = m;
	}
	printf("%.9lf\n", (be+en)/2.0);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}