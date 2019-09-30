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

const int MAX = 200 * 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

struct Item
{
	int x, v, ind;
	bool operator <(const Item& a) const
	{
		return x < a.x;
	}
};

bool cmp(const Item& a, const Item& b)
{
	return a.v < b.v;
}

struct FenvicMin
{
	int T[MAX];
	int n;

	void init(int n1)
	{
		n = n1;
		FOR(i, 0, n)
		{
			T[i] = INF;
		}
	}

	int get(int i)
	{
		int res = INF;
		for (; i >= 0; i = (i & (i + 1)) - 1)
		{
			res = min(res, T[i]);
		}

		return res;
	}

	void upd(int i, int val)
	{
		for (; i < n; i = i | (i + 1))
		{
			T[i] = min(T[i], val);
		}
	}

	int getSuf(int i)
	{
		return get(n - i - 1);
	}

	void updSuf(int i, int val)
	{
		upd(n - i - 1, val);
	}
} RM;

void ADD(int& key, int val)
{
	key += val;
	if (key >= MOD) key -= MOD;
}

struct FenvicSum
{
	int T[MAX];
	int n;

	void intit(int n1)
	{
		n = n1;
	}

	int get(int i)
	{
		int res = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1)
		{
			ADD(res, T[i]);
		}

		return res;
	}

	int get(int l, int r)
	{
		int res = get(r) - get(l - 1);
		if (res < 0) res += MOD;
		return res;
	}

	void add(int i, int d)
	{
		for (; i < n; i = i | (i + 1))
		{
			ADD(T[i], d);
		}
	}
} RS;

Item A[MAX];
int P[MAX];
PII B[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> A[i].x >> A[i].v;
	}

	sort(A, A + n);
	FOR(i, 0, n) A[i].ind = i;
	sort(A, A + n, cmp);
	FOR(i, 0, n) P[i] = A[i].ind;
	RM.init(n);
	FOR(i, 0, n)
	{
		int ind = RM.getSuf(P[i]);
		B[i].first = ind == INF ? i : ind;
		RM.updSuf(P[i], i);
	}

	RM.init(n);
	RFOR(i, n, 0)
	{
		int ind = RM.get(P[i]) * -1;
		B[i].second = ind == -INF ? i : ind;

		RM.upd(P[i], -i);
	}

	sort(B, B + n);

	RS.intit(n);
	FOR(i, 0, n)
	{
		int l = B[i].first;
		int r = B[i].second;

		int s = RS.get(max(l - 1, 0), r);
		if (l == 0) ADD(s, 1);

		//cout << i << " " << s << endl;
		RS.add(r, s);
	}

	int res = RS.get(n - 1, n - 1);
	cout << res << endl;
}