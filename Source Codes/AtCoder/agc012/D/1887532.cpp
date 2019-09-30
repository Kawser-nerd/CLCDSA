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

const int MAX = 4 * 1000 * 100 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

int n, x, y;
PII A[MAX];
LL F[MAX];
LL FR[MAX];
map<int, int> mapp;
int C[MAX];
int P[MAX];

LL bp(LL a, int n)
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

LL inv(LL a)
{
	return bp(a, MOD - 2);
}

struct DSU
{
	int P[MAX];
	multiset<int> S[MAX];
	void init()
	{
		FOR(i, 0, n)
		{
			P[i] = i;
			S[i].insert(A[i].second);
		}
	}

	int getParent(int v)
	{
		if (P[v] == v) return v;
		return P[v] = getParent(P[v]);
	}

	void unionSet(int a, int b)
	{
		a = getParent(a);
		b = getParent(b);

		if (a == b) return;
		if (SZ(S[a]) < SZ(S[b])) swap(a, b);

		for (auto i = S[b].begin(); i != S[b].end(); i++)
		{
			S[a].insert(*i);
		}

		P[b] = a;
	}

	LL calc()
	{
		LL ans = 1;
		FOR(i, 0, n)
		{
			if (P[i] != i) continue;

			LL all = SZ(S[i]);
			LL res = F[all];
			mapp.clear();
			for (auto it = S[i].begin(); it != S[i].end(); it++)
			{
				mapp[*it]++;
			}

			for (auto it = mapp.begin(); it != mapp.end(); it++)
			{
				res = (res * FR[it->second]) % MOD;
			}

			ans = (ans * res) % MOD;
		}

		return ans;
	}
} D;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	F[0] = FR[0] = 1;
	FOR(i, 1, MAX)
	{
		F[i] = (F[i - 1] * i) % MOD;
		FR[i] = inv(F[i]);
	}

	cin >> n >> x >> y;
	FOR(i, 0, n)
	{
		cin >> A[i].second >> A[i].first;
	}

	sort(A, A + n);
	FILL(C, -1);
	FOR(i, 0, n)
	{
		int c = A[i].second;
		P[i] = C[c];
		if (C[c] == -1) C[c] = i;
	}

	int p = -1;
	FOR(i, 0, n)
	{
		if (A[i].second != A[0].second)
		{
			p = i;
			break;
		}
	}

	D.init();
	FOR(i, 1, n)
	{
		if (A[i].second == A[0].second)
		{
			if (A[i].first + A[0].first <= x)
			{
				D.unionSet(0, i);
			}

			if (p != -1 && A[i].first + A[p].first <= y)
			{
				D.unionSet(p, i);
			}

			continue;
		}

		if (A[i].first + A[0].first <= y)
		{
			D.unionSet(i, 0);
		}

		if (P[i] != -1 && A[i].first + A[P[i]].first <= x)
		{
			D.unionSet(i, P[i]);
		}
	}

	LL ans = D.calc();
	cout << ans << endl;
}