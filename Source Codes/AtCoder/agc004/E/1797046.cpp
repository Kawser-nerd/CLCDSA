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
#include<unordered_set>
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

const int MAX = 100 + 47;

string s;
int ROW[MAX][MAX];
int COL[MAX][MAX];
int dp[3][MAX][MAX][MAX];

void Max(int& key, int val)
{
	key = max(key, val);
}

int getCol(int col, int i, int j)
{
	if (i > j) return 0;
	int res = COL[j][col];
	if (i) res -= COL[i - 1][col];
	return res;
}

int getRow(int row, int i, int j)
{
	if (i > j) return 0;
	int res = ROW[row][j];
	if (i) res -= ROW[row][i - 1];
	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int h, w, x, y;
	cin >> h >> w;
	FOR(i, 0, h)
	{
		cin >> s;
		FOR(j, 0, SZ(s))
		{
			if (s[j] == 'o')
			{
				COL[i][j] = 1;
				ROW[i][j] = 1;
			}

			if (j) ROW[i][j] += ROW[i][j - 1];
			if (i) COL[i][j] += COL[i - 1][j];

			if (s[j] == 'E')
			{
				x = i;
				y = j;
			}
		}
	}

	FILL(dp, -1);
	dp[0][0][0][0] = 0;
	int ans = 0;
	int C = 0;
	int N = 1;
	//cout << w << ""
	//cout << x << " " << y << endl;

	FOR(L, 0, w + 1)
	{
		FOR(R, 0, w + 1)
		{
			FOR(U, 0, h + 1)
			{
				FOR(D, 0, h + 1)
				{
					//cout << L << " " << R << " " << U << " " << D << endl;
					if (dp[C][R][U][D] == -1) continue;
					//cout << L << " " << R << " " << U << " " << D << ": " << dp[C][R][U][D] << endl;
					ans = max(ans, dp[C][R][U][D]);
					{
						int l = max(R, y - L);
						int r = min(y + R, w - 1 - L);

						if (h - 1 - x - U - D > 0)
						{
							Max(dp[C][R][U][D + 1], dp[C][R][U][D] + getRow(x + D + 1, l, r));
						}

						if (x - D - U > 0)
						{
							//cout << "*" << endl;
							Max(dp[C][R][U + 1][D], dp[C][R][U][D] + getRow(x - U - 1, l, r));
							//cout << dp[C][R][U + 1][D] << endl;
						}
					}
					
					{
						int l = max(D, x - U);
						int r = min(x + D, h - 1 - U);
						if (w - 1 - y - L - R > 0)
						{
							Max(dp[C][R + 1][U][D], dp[C][R][U][D] + getCol(y + R + 1, l, r));
						}

						if (y - L - R > 0)
						{
							Max(dp[N][R][U][D], dp[C][R][U][D] + getCol(y - L - 1, l, r));
						}
					}
				}
			}
		}

		swap(C, N);
		FOR(R, 0, w + 1)
		{
			FOR(U, 0, h + 1)
			{
				FOR(D, 0, h + 1)
				{
					dp[N][R][U][D] = -1;
				}
			}
		}
	}
	//FOR(L, 0, y + 1)
	//{
	//	FOR(R, 0, w - y)
	//	{
	//		FOR(U, 0, x + 1)
	//		{
	//			FOR(D, 0, h - x)
	//			{
	//				cout << L << " " << R << " " << U << " " << D << ": " << dp[L][R][U][D] << endl;
	//			}
	//		}
	//	}
	//}

	cout << ans << endl;
}