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

const int MAX = 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

string A[MAX];
struct Matrix
{
	LL T[2][2];
	Matrix()
	{
		FOR(i, 0, 2) FOR(j, 0, 2) T[i][j] = 0;
	}

	void one()
	{
		T[0][0] = T[1][1] = 1;
	}

	void operator *=(Matrix a)
	{
		LL R[2][2] = {0};
		FOR(i, 0, 2)
		{
			FOR(j, 0, 2)
			{
				FOR(k, 0, 2)
				{
					R[i][j] = (R[i][j] + T[i][k] * a.T[k][j]) % MOD;
				}
			}
		}

		FOR(i, 0, 2)
		{
			FOR(j, 0, 2) T[i][j] = R[i][j];
		}
	}

	void print()
	{
		FOR(i, 0, 2)
		{
			FOR(j, 0, 2) cout << T[i][j] << " ";
			cout << endl;
		}
	}
};

void bp(Matrix& A, LL k)
{
	Matrix R;
	R.one();

	while (k)
	{
		if (k & 1)
		{
			R *= A;
		}

		k >>= 1;
		A *= A;
	}

	FOR(i, 0, 2)
	{
		FOR(j, 0, 2) A.T[i][j] = R.T[i][j];
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	LL k;
	cin >> n >> m >> k;

	FOR(i, 0, n) cin >> A[i];
	LL cnt = 0;
	bool ver = false;
	bool hor = false;
	FOR(i, 0, n)
	{
		if (A[i][0] == A[i][m - 1] && A[i][0] == '#') hor = true;
	}

	FOR(j, 0, m)
	{
		if (A[0][j] == A[n - 1][j] && A[0][j] == '#') ver = true;
	}
	
	FOR(i, 0, n)
	{
		FOR(j, 0, m) cnt += A[i][j] == '#';
	}

	if (ver && hor)
	{
		cout << 1 << endl;
		return 0;
	}

	if (!ver && !hor)
	{
		Matrix res;
		res.T[0][0] = cnt;
		bp(res, k - 1);
		cout << res.T[0][0] << endl;
		return 0;
	}

	LL w = 0;
	LL b = 0;

	if (hor)
	{
		FOR(i,0,n)
		{
			FOR(j, 1, m)
			{
				if (A[i][j] == A[i][j - 1] && A[i][j] == '#') w++;
			}

			if (A[i][0] == A[i][m - 1] && A[i][0] == '#') b++;
		}
	}
	else
	{
		FOR(j, 0, m)
		{
			FOR(i, 1, n)
			{
				if (A[i - 1][j] == A[i][j] && A[i][j] == '#') w++;
			}

			if (A[0][j] == A[n - 1][j] && A[0][j] == '#') b++;
		}
	}

	Matrix res;
	res.T[0][0] = b;
	res.T[0][1] = w;
	res.T[1][0] = 0;
	res.T[1][1] = cnt;
	//res.print();

	bp(res, k - 1);
	w = res.T[0][1];
	b = res.T[1][1];
	cout << (b - w + MOD) % MOD << endl;
}