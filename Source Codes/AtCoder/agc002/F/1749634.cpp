#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
//typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX1 = 2000 + 47;
const int MAX = MAX1 * MAX1 + 47;

LL F[MAX];
LL FR[MAX];
LL dp[MAX1][MAX1];

LL bp(LL a, LL n)
{
	LL res = 1;
	while (n)
	{
		if (n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		n >>= 1;
	}

	return res;
}

LL c(int n, int k)
{
	if (n < k) return 0;
	LL res = (F[n] * FR[n - k]) % MOD;
	res = (res * FR[k]) % MOD;
	return res;
}

void ADD(LL& key, LL val)
{
	key = key + val;
	if (key >= MOD) key -= MOD;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	F[0] = 1;
	FR[0] = bp(1, MOD - 2);
	FOR(i, 1, MAX)
	{
		F[i] = (F[i - 1] * i) % MOD;
		FR[i] = bp(F[i], MOD - 2);
	}

	int n, k;
	cin >> n >> k;
	if (k == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	dp[0][0] = 1;
	FOR(i, 0, n + 1)
	{
		FOR(j, 0, n + 1)
		{
			if (i + 1 <= n)
			{
				ADD(dp[i + 1][j], dp[i][j]);
			}

			if (i - j > 0)
			{
				int left = n * k - i - j * (k - 1);
				LL w = (c(left - 1, k - 2) * (n - j)) % MOD;
				//cout << i << " " << j << ": " << w << endl;
				ADD(dp[i][j + 1], (dp[i][j] * w) % MOD);
			}

		}
	}

	//FOR(i, 0, n + 1)
	//{
	//	FOR(j, 0, n + 1) cout << dp[i][j] << " ";
	//	cout << endl;
	//}

	cout << dp[n][n] << endl;
}