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

const int L = 20;
const int MAX = 2 * 1000 * 100 + 47;

int V[L];
int sz = 0;
int N[L][MAX];
int P[L][MAX];
int X[MAX];
int dpL[1 << L];
int dpR[1 << L];
int ANS[MAX];
set<PII> S;
int M[MAX];

void print(int mask)
{
	while (mask)
	{
		if (mask & 1)
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}

		mask >>= 1;
	}
}

//#define DEBUG
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	int n, v;
	cin >> n >> v;
	FOR(i, 0, n) cin >> X[i];

	V[0] = v;
	FOR(i, 1, L)
	{
		V[i] = V[i - 1] / 2;
		if (V[i] == 0)
		{
			sz = i + 1;
			break;
		}
	}

	reverse(V, V + sz);
	FOR(k, 0, sz)
	{
		int v = V[k];
		N[k][n - 1] = n;

		RFOR(i, n - 1, 0)
		{
			if (abs(X[i + 1] - X[i]) > v)
			{
				N[k][i] = i + 1;
				continue;
			}

			N[k][i] = N[k][i + 1];
		}
	}

#ifdef DEBUG
	cout << "N=" << endl;
	FOR(k, 0, sz)
	{
		cout << V[k] << ": ";
		FOR(i, 0, n)
		{
			cout << N[k][i] << " ";
		}

		cout << endl;
	}
#endif

	FOR(k, 0, sz)
	{
		int v = V[k];
		P[k][0] = -1;
		FOR(i, 1, n)
		{
			if (abs(X[i] - X[i - 1]) > v)
			{
				P[k][i] = i - 1;
				continue;
			}

			P[k][i] = P[k][i - 1];
		}
	}

#ifdef DEBUG
	cout << "P=" << endl;
	FOR(k, 0, sz)
	{
		cout << V[k] << ": ";
		FOR(i, 0, n)
		{
			cout << P[k][i] << " ";
		}

		cout << endl;
	}
#endif

	sz--;

	dpL[0] = 0;
	FOR(mask, 0, 1 << sz)
	{
		int x = dpL[mask];
		FOR(k, 0, sz)
		{
			if (mask & (1 << k)) continue;

			dpL[mask | (1 << k)] = max(dpL[mask | (1 << k)], N[k][x]);
		}
	}

#ifdef DEBUG
	cout << "dpL" << endl;
	FOR(mask, 0, 1 << sz)
	{
		print(mask);
		cout << " :";
		cout << dpL[mask] << endl;
	}
#endif

	FOR(i, 0, 1 << sz) dpR[i] = 10 + n;
	dpR[0] = n - 1;
	FOR(mask, 0, 1 << sz)
	{
		int x = dpR[mask];
		FOR(k, 0, sz)
		{
			if (mask & (1 << k)) continue;

			dpR[mask | (1 << k)] = min(dpR[mask | (1 << k)], P[k][x]);
		}
	}


#ifdef DEBUG
	cout << "dpR" << endl;
	FOR(mask, 0, 1 << sz)
	{
		print(mask);
		cout << " :";
		cout << dpR[mask] << endl;
	}
#endif

	FOR(i, 0, n) M[i] = INF;
	int tmp = INF;
	FOR(maskL, 0, 1 << sz)
	{
		int maskR = ((1 << sz) - 1) ^ maskL;
		int l = dpL[maskL] - 1;
		int r = dpR[maskR] + 1;
#ifdef DEBUG
		cout << "!!" << l << " " << r << endl;
#endif
		if (l != -1) M[l] = min(M[l], r);

		if (l == -1) tmp = min(tmp, r);
	}

#ifdef DEBUG
	cout << "M=" << endl;
	FOR(i, 0, n)
	{
		cout << M[i] << " ";
	}

	cout << endl;
#endif

	RFOR(i, n - 1, 0) M[i] = min(M[i + 1], M[i]);
	
	FOR(i, 0, n)
	{
		int l = P[sz][i] + 1;
		int r = N[sz][i] - 1;
		if (S.find(MP(l, r)) != S.end()) continue;
		S.insert(MP(l, r));

		int val = M[max(l - 1, 0)];
		if (l - 1 == -1)
		{
			val = min(val, tmp);
		}

		if (val <= r + 1)
		{
			FOR(k, l, r + 1) ANS[k] = 1;
		}
	}

	FOR(i, 0, n)
	{
		if (ANS[i])
		{
			cout << "Possible" << endl;
			continue;
		}

		cout << "Impossible" << endl;
	}
}