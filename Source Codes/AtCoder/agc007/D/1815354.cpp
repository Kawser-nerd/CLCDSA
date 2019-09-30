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

const int MAX = 1000 * 1000 + 47;

int n, e, t;
int X[MAX];
LL dp[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, e, t;
	cin >> n >> e >> t;
	FOR(i, 0, n)
	{
		cin >> X[i];
	}

	FOR(i, 0, n + 1) dp[i] = INF;
	dp[0] = 0;
	int p = 0;
	LL minn = LINF;

	FOR(i, 1, n + 1)
	{
		while (2 * (X[i - 1] - X[p]) > t)
		{
			minn = min(dp[p] - 2 * X[p], minn);
			p++;
		}

		dp[i] = minn + 2 * X[i - 1];
		dp[i] = min(dp[i], dp[p] + t);
	}

	cout << dp[n] + e;
}