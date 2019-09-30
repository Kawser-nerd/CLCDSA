#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<long double, long double> PDD;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 1500;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

int dp[MAX][2 * MAX][2];
bool A[2][MAX];
int main()
{
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);

	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		int n , m;
		cin >> n >> m;
		FILL(A,0);

		FOR(i,0,n)
		{
			int a , b;
			cin >> a >> b;
			FOR(j,a,b) A[0][j] = 1;
		}
		FOR(i,0,m)
		{
			int a , b;
			cin >> a >> b;
			FOR(j,a,b) A[1][j] = 1;
		}

		FOR(i,0,MAX)
			FOR(j,0,2 * MAX)
				FOR(k,0,2)
					dp[i][j][k] = INF;

		dp[0][MAX][0] = 0;

		FOR(i,0,24 * 60)
		{
			FOR(j,0,2 * MAX)
			{
				FOR(k,0,2)
				{
					FOR(l,0,2)
					{
						if (A[l][i]) continue;
						if (dp[i][j][k] == INF) continue;
						int nbal = j;
						if (l == 0) nbal ++;
						else nbal --;
						int nval = dp[i][j][k];
						if (l != k) nval ++;

						dp[i + 1][nbal][l] = min(dp[i + 1][nbal][l] , nval);
					}
				}
			}
		}

		int res = min(dp[24 * 60][MAX][0] , dp[24 * 60][MAX][1] + 1);

		FOR(i,0,MAX)
			FOR(j,0,2 * MAX)
				FOR(k,0,2)
					dp[i][j][k] = INF;

		dp[0][MAX][1] = 0;

		FOR(i,0,24 * 60)
		{
			FOR(j,0,2 * MAX)
			{
				FOR(k,0,2)
				{
					FOR(l,0,2)
					{
						if (A[l][i]) continue;
						if (dp[i][j][k] == INF) continue;
						int nbal = j;
						if (l == 0) nbal ++;
						else nbal --;
						int nval = dp[i][j][k];
						if (l != k) nval ++;

						dp[i + 1][nbal][l] = min(dp[i + 1][nbal][l] , nval);
					}
				}
			}
		}

		res = min(res , min(dp[24 * 60][MAX][0] + 1 , dp[24 * 60][MAX][1]));


		cerr << tt << ' ' << res << endl;
		printf("Case #%d: %d\n" , tt + 1 , res);

	}

    return 0;
}
