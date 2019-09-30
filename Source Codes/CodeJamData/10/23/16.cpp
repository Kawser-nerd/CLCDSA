#include <iostream>
#include <fstream>
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

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR2(i, a, b) for (int i = (a); i > (b); --i)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

/*inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=last_bit(n); return res; }*/

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const ll MOD = 100003;
const int MAX = 501;
ll dp[MAX][MAX]; //[N][i] - kolko je moznosti, ake je N-ko i-te v poradi
ll comb[MAX][MAX];

void Solve(int tc)
{
	int N;
	cin >> N;

	int res = 0;
	FOR(i, 1, N) res = (res + dp[N][i]) % MOD;
	cout << "Case #" << tc << ": " << res << endl;
}

int main()
{
	comb[0][0] = 1;
	FOR(i, 1, MAX)
	{
		comb[i][0] = 1;
		FOR(j, 1, i+1)
			comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
	}

	FOR(N, 2, MAX)
	{
		dp[N][1] = 1;
		FOR(pos, 2, N)
		{
			FOR(next, 1, pos)
			{
				dp[N][pos] = (dp[N][pos] + dp[pos][next] * comb[N-pos-1][pos-next-1]) % MOD;
			}
		}
	}

	int T;
	cin >> T;
	FOR(step, 0, T) Solve(step+1);

	return 0;
}