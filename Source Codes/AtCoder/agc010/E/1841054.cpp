#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:128777216")
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
typedef pair<long long, long long> PLL;


const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 2000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

//#define DEBUG
int A[MAX];
int IND[MAX];

vector<int> g[MAX];
int U[MAX];
vector<int> L[MAX];
vector<int> P;
int sz;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int merge(int v, vector<int> A)
{
	if (v != -1)
	{
		L[sz].push_back(v);
	}

	P.assign(SZ(A), 0);
	while (1)
	{
		int ind = -1;
		FOR(i, 0, SZ(A))
		{
			if (P[i] < SZ(L[A[i]]))
			{
				ind = i;
				break;
			}
		}

		if (ind == -1) break;
		FOR(i, 0, SZ(A))
		{
			if (P[i] < SZ(L[A[i]]) && L[A[i]][P[i]] > L[A[ind]][P[ind]])
			{
				ind = i;
			}
		}

		L[sz].push_back(L[A[ind]][P[ind]]);
		P[ind]++;
	}

	sz++;
	return sz - 1;
}

int dfs(int v)
{
	U[v] = 1;
	vector<int> A;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (U[to]) continue;
		A.push_back(dfs(to));
	}

	return merge(v, A);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> A[i];
	}

	sort(A, A + n);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (i == j) continue;
			if (gcd(A[i], A[j]) == 1) continue;
			g[i].push_back(j);
		}
	}

	FOR(i, 0, n)
	{
		sort(ALL(g[i]));
	}

#ifdef DEBUG
	cout << "B=" << endl;
	FOR(i, 0, n)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "g=" << endl;
	FOR(i, 0, n)
	{
		cout << i << ": ";
		FOR(j, 0, SZ(g[i])) cout << g[i][j] << " ";
		cout << endl;
	}
#endif
	vector<int> D;
	FOR(i, 0, n)
	{
		if (!U[i])
		{
			D.push_back(dfs(i));
		}
	}

	int p = merge(-1, D);
	FOR(i, 0, SZ(L[p]))
	{
		int ind = L[p][i];
		cout << A[ind] << " ";
	}

	cout << endl;
}