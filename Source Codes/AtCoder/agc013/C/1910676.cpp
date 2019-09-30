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

const int MAX = 1000 * 100 + 47;

int Y[MAX];
int X[MAX];
int W[MAX];
int t, l;

int getD(int x, int y, int d)
{
	if (d == 2) swap(x, y);
	if (x <= y) return y - x;
	return y + l - x;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> l >> t;
	FOR(i, 0, n)
	{
		cin >> X[i] >> W[i];
	}

	FOR(i, 0, n)
	{
		if (W[i] == 1)
		{
			Y[i] = (X[i] + t) % l;
			//Y[i] = MP((X[i] + t) % l, W[i]);
		}
		else
		{
			Y[i] = (X[i] - t % l + l) % l;
			//Y[i] = MP((X[i] - t % l + l) % l, W[i]);
		}
	}

	int cnt = 0;
	FOR(i, 1, n)
	{
		if (W[i] == W[0]) continue;
		int d = getD(X[0], X[i], W[0]);
		int c = (2 * t - d) / l;
		//if ((2 * t - d) % l == 0) c--;
		//if (c == -1) c = n - 1;
		if (d <= 2 * t) c++;
		c = c % n;
		cnt = (c + cnt) % n;
	}

	if (W[0] == 2) cnt = n - cnt;
	int y = Y[0];
	sort(Y, Y + n);
	int ind = lower_bound(Y, Y + n, y) - Y;
	if (ind + 1 < n && Y[ind] == Y[ind + 1])
	{
		if (W[0] == 1) ind++;
	}

	ind = (ind - cnt + n) % n;
	FOR(i, 0, n)
	{
		if (ind == n) ind = 0;

		cout << Y[ind] << "\n";
		ind++;
	}
}