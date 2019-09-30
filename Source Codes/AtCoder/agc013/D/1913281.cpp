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
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 3 * 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[MAX][MAX][2];

void ADD(int& key, int val)
{
	key += val;
	if (key >= MOD) key -= MOD;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	dp[0][0][1] = 1;
	FOR(j, 1, n + 1)
	{
		dp[0][j][0] = 1;
	}

	FOR(i, 0, m)
	{
		FOR(j, 0, n + 1)
		{
			FOR(t, 0, 2)
			{
				if (j > 0)
				{
					int newT = j == 1 ? 1 : t;
					ADD(dp[i + 1][j - 1][newT], dp[i][j][t]);
				}

				if (j < n)
				{
					ADD(dp[i + 1][j + 1][t], dp[i][j][t]);
				}

				if (j < n)
				{
					ADD(dp[i + 1][j][t], dp[i][j][t]);
				}

				if (j)
				{
					int newT = j == 1 ? 1 : t;
					ADD(dp[i + 1][j][newT], dp[i][j][t]);
				}
			}
		}
	}

	//FOR(i, 0, m + 1)
	//{
	//	FOR(j, 0, n + 1)
	//	{
	//		FOR(t, 0, 2)
	//		{
	//			cout << i << " " << j << " " << t << ": " << dp[i][j][t] << endl;
	//		}
	//	}
	//}

	int ans = 0;
	FOR(i, 0, n + 1)
	{
		ADD(ans, dp[m][i][1]);
	}

	cout << ans << endl;
}