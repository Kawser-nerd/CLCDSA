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

const int MAX = 2 * 1000 * 100 + 47;

int A[MAX];
int B[MAX];

int A1[MAX];
int B1[MAX];
int L[MAX * 2];
int sz;
vector<int> g[MAX];
int IN[MAX];
int OUT[MAX];
int U[MAX];

int val = 0;
void dfs(int v)
{
	if (U[v]) return;
	U[v] = 1;

	if (OUT[v] > IN[v]) val += OUT[v] - IN[v];
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs(to);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	FOR(i, 0, n) cin >> B[i];
	

	int y = 0;
	int x = 0;
	FOR(i, 0, n)
	{
		x ^= A[i];
		y ^= B[i];
		A1[i] = A[i];
		B1[i] = B[i];
	}

	A1[n] = x;
	B1[n] = y;
	sort(A1, A1 + n + 1);
	sort(B1, B1 + n + 1);
	bool ok = true;
	FOR(i, 0, n + 1)
	{
		if (A1[i] != B1[i])
		{
			ok = false;
			break;
		}
	}

	if (!ok)
	{
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;
	FOR(i, 0, n)
	{
		if (A[i] != B[i]) ans++;
		L[sz++] = A[i];
		L[sz++] = B[i];
	}

	L[sz++] = x;
	sort(L, L + sz);
	sz = unique(L, L + sz) - L;
	
	FOR(i, 0, n)
	{
		A[i] = lower_bound(L, L + sz, A[i]) - L;
		B[i] = lower_bound(L, L + sz, B[i]) - L;
	}

	x = lower_bound(L, L + sz, x) - L;
	FOR(i, 0, n)
	{
		int a = A[i];
		int b = B[i];
		if (a == b) continue;
		g[a].push_back(b);
		g[b].push_back(a);

		OUT[b]++;
		IN[a]++;
	}

	val = 0;
	dfs(x);
	if (val != 0 && OUT[x] > IN[x]) val--;
	ans += val;

	FOR(i, 0, n)
	{
		//cout << SZ(g[i]) << endl;
		if (U[i] || SZ(g[i]) == 0) continue;

		val = 0;
		dfs(i);
		if (val == 0) val++;
		//cout << i << ": " << val << endl;
		ans += val;
	}

	cout << ans << endl;
}