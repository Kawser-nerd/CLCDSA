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

const int MAX = 2 * 1000 * 100 + 47;

struct Fenvic
{
	int T[MAX];
	int n;
	void init(int n1)
	{
		n = n1;
		FOR(i, 0, n) T[i] = 0;
	}

	void add(int i, int delta)
	{
		for (; i < n; i = i | (i + 1))
		{
			T[i] += delta;
		}
	}

	int get(int i)
	{
		int res = 0;
		for (; i >= 0; i = (i & (i + 1)) - 1)
		{
			res += T[i];
		}

		return res;
	}

	int get(int l, int r)
	{
		int res = get(r);
		if (l) res -= get(l - 1);
		return res;
	}
} F;

int A[MAX];
int B[MAX];
int C[3][MAX];

void no()
{
	cout << "No" << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, 3)
	{
		FOR(j, 0, n)
		{
			cin >> C[i][j];
			C[i][j]--;
		}
	}

	FOR(j, 0, n)
	{
		if (C[0][j] / 3 != C[1][j] / 3 || C[0][j] / 3 != C[2][j] / 3) no();

		A[j] = C[0][j] / 3;
		if (C[0][j] < C[1][j] && C[1][j] < C[2][j])
		{
			B[j] = 0;
			continue;
		}

		if (C[0][j] > C[1][j] && C[1][j] > C[2][j])
		{
			B[j] = 1;
			continue;
		}

		no();
	}

	FOR(i, 0, n)
	{
		if (A[i] % 2 != i % 2) no();
	}

	F.init(n);
	int odd = 0;
	for (int i = 0; i < n; i += 2)
	{
		odd ^= F.get(A[i] + 1, n - 1) % 2;
		F.add(A[i], 1);
	}

	F.init(n);
	int even = 0;
	for (int i = 1; i < n; i += 2)
	{
		even ^= F.get(A[i] + 1, n - 1) % 2;
		F.add(A[i], 1);
	}

	FOR(i, 0, n)
	{
		if (i % 2 == 0 && B[i] == 1) even ^= 1;
		if (i % 2 == 1 && B[i] == 1) odd ^= 1;
	}

	if (odd == 0 && even == 0)
	{
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;
}