#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

const int maxn = 510;
const int64 mod = 100003LL;

int64 d[maxn][maxn];
int64 C[maxn + 10][maxn + 10];

int solve0(int n)
{
	int res = 0;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (mask & 1) continue;
		int cur = n;
		bool ok = true;
		while (cur > 1)
		{
			if (!((mask >> (cur - 1)) & 1))
			{
				ok = false;
				break;
			}
			int cnt = 0;
			for (int i = 0; i < cur; i++)
				if ((mask >> i) & 1) cnt++;
			cur = cnt;
		}
		if (ok) res++;
	}
	return res;
}

void Solve()
{
	int n;
	cin >> n;
	int64 res = 0;
	for (int i = 0; i <= n; i++)
		res += d[i][n];
	//cout << solve0(n) << " " << res << "\n";
	cout << (res % mod) << "\n";
}

int main()
{
	memset(d, 0, sizeof(d));
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j < maxn; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	d[0][1] = 1;
	for (int i = 1; i < maxn; i++)
		for (int j = i + 1; j < maxn; j++)
		{
			for (int k = 0; k <= i - 1; k++)
			{
				d[i][j] += d[k][i] * C[j - i - 1][i - 1 - k];
				d[i][j] %= mod;
			}
		}
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; it++)
	{
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}
