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

const int MAX = 1000 * 100 + 47;
LL A[MAX];
LL C[MAX];
int U[MAX];

void no()
{
	cout << "NO" << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];

	LL s = 0;
	FOR(i, 0, n)
	{
		s += A[i];
	}

	LL all = n *(LL) (n + 1) / 2;
	if (s % all != 0) no();

	LL cnt = s / all;
	FOR(i, 0, n)
	{
		int nex = i + 1;
		if (nex == n) nex = 0;
		if ((A[i] - A[nex] + cnt) % n != 0) no();
		C[nex] = (A[i] - A[nex] + cnt) / n;
	}

	LL dod = 0;
	LL c = 0;
	FOR(k, 0, 2 * n)
	{
		int i = k % n;
		int nex = i + 1;
		if (nex == n) nex = 0;

		if (U[i])
		{
			c -= C[i];
			dod -= (n + 1) * C[i];
			C[i] = 0;
		}
		else
		{
			U[i] = 1;
			c += C[i];
			dod += C[i];
		}

		if (A[i] - dod < 0) no();
		A[i] -= dod;
		dod += c;
	}

	FOR(i, 0, n)
	{
		if (A[i] != 0) no();
	}

	cout << "YES" << endl;
}