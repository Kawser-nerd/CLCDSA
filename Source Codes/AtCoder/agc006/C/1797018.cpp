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

const int MAX = 100000 + 47;

int X[MAX];
int DX[MAX];
int P[MAX];
int T[MAX];
int RES[MAX];
int n, m;
LL k;

void mult(int P[], int Q[])
{
	FOR(i, 0, n - 1) T[i] = Q[i];
	
	FOR(i, 0, n - 1)
	{
		P[i] = T[P[i]];
	}
}

void bp(int P[], LL k, int RES[])
{
	FOR(i, 0, n - 1) RES[i] = i;

	while (k)
	{
		if (k & 1) mult(RES, P);

		mult(P, P);
		k >>= 1;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	FOR(i, 0, n) cin >> X[i];

	FOR(i, 0, n - 1)
	{
		DX[i] = X[i + 1] - X[i];
	}

	FOR(i, 0, n - 1)
	{
		P[i] = i;
	}

	cin >> m >> k;
	FOR(i, 0, m)
	{
		int a;
		cin >> a;
		a--;
		swap(P[a - 1], P[a]);
	}

	bp(P, k, RES);

	cout << X[0] << "\n";
	LL x = X[0];

	FOR(i, 0, n - 1)
	{
		x += DX[RES[i]];
		cout << x << "\n";
	}
}