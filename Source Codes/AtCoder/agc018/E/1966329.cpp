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

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX = 2 * 1000 * 1000 + 47;

struct Item
{
	LL x, y, mult;
	Item() {}
	Item(LL x1, LL y1, LL mult1)
	{
		x = x1;
		y = y1;
		mult = mult1;
	}
};

LL F[MAX];
LL FR[MAX];
LL R[MAX];
LL X[6];
LL Y[6];
Item S[4];
Item E[4];

LL cc(int n, int k)
{
	if (k > n) return 0;
	LL res = (F[n] * FR[k]) % MOD;
	res = (res * FR[n - k]) % MOD;
	return res;
}

LL C(int x, int y)
{
	return cc(x + y, x);
}

void ADD(LL& key, LL val)
{
	key += val;
	if (key >= MOD) key -= MOD;

	if (key < 0) key += MOD;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	F[0] = F[1] = FR[0] = FR[1] = R[1] = 1;

	FOR(i, 2, MAX)
	{
		R[i] = MOD - (MOD / i * R[MOD % i]) % MOD;
		if (R[i] == MOD) R[i] = 0;
		F[i] = (F[i - 1] * i) % MOD;
		FR[i] = (FR[i - 1] * R[i]) % MOD;
	}

	FOR(i, 0, 6) cin >> X[i];
	FOR(i, 0, 6) cin >> Y[i];

	S[0] = Item(X[0] - 1, Y[0] - 1, 1);
	S[1] = Item(X[1], Y[1], 1);
	S[2] = Item(X[0] - 1, Y[1], -1);
	S[3] = Item(X[1], Y[0] - 1, -1);

	E[0] = Item(X[5] + 1, Y[5] + 1, 1);
	E[1] = Item(X[4], Y[4], 1);
	E[2] = Item(X[4], Y[5] + 1, -1);
	E[3] = Item(X[5] + 1, Y[4], -1);

	LL ans = 0;
	FOR(s, 0, 4)
	{
		FOR(e, 0, 4)
		{
			int mult = S[s].mult * E[e].mult;

			FOR(x, X[2], X[3] + 1)
			{
				LL val = C(E[e].x - x, E[e].y - Y[3] - 1) * (x + Y[3] + 1);
				val %= MOD;
				val *= C(x - S[s].x, Y[3] - S[s].y);
				val %= MOD;

				ADD(ans, mult * val);
			}

			FOR(y, Y[2], Y[3] + 1)
			{
				LL val = C(E[e].x - X[3] - 1, E[e].y - y) * (y + X[3] + 1);
				val %= MOD;
				val *= C(X[3] - S[s].x, y - S[s].y);
				val %= MOD;
				
				ADD(ans, mult * val);
			}

			FOR(x, X[2], X[3] + 1)
			{
				LL val = C(x - S[s].x, Y[2] - 1 - S[s].y) * (-(x + Y[2]));
				val %= MOD;
				val *= C(E[e].x - x, E[e].y - Y[2]);
				val %= MOD;

				ADD(ans, mult * val);
			}

			FOR(y, Y[2], Y[3] + 1)
			{
				LL val = C(X[2] - 1 - S[s].x, y - S[s].y) * (-(X[2] + y));
				val %= MOD;
				val *= C(E[e].x - X[2], E[e].y - y);
				val %= MOD;

				ADD(ans, mult * val);
			}
		}
	}

	cout << ans << endl;
}