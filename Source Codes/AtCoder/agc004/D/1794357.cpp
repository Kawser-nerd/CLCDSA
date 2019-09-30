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

const int MAX = 5 * 1000 * 100 + 47;

int A[MAX];
int H[MAX];
vector<int> g[MAX];
int res = 0;
int n, k;

void dfs(int v, int d)
{
	H[v] = 0;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs(to, d + 1);
		H[v] = max(H[v], H[to] + 1);
	}

	if (H[v] == k - 1 && d > 1)
	{
		res++;
		H[v] = -1;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		a--;
		A[i] = a;
		if (i)
		{
			g[a].push_back(i);
		}
	}

	if (A[0] != 0) res++;
	dfs(0, 0);
	cout << res << endl;
}