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

const int MAX = 3000 + 47;

vector<int> g[MAX];
int A[MAX];
int L[MAX];

bool isWin(int v)
{
	if (L[v]) return false;

	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (A[to] < A[v])
		{
			if (!isWin(to)) return true;
		}
	}

	return false;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	FOR(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	FOR(v, 0, n)
	{
		bool lose = true;
		FOR(i, 0, SZ(g[v]))
		{
			int to = g[v][i];
			if (A[to] < A[v])
			{
				lose = false;
				break;
			}
		}

		L[v] = lose;
	}

	FOR(v, 0, n)
	{
		if (isWin(v))
		{
			cout << v + 1 << " ";
		}
	}

	cout << endl;
}