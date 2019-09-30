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

const int MAX = 2 * 1000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

string A[MAX];
int P1[MAX][MAX];
int P2[MAX][MAX];
int P3[MAX][MAX];

void recalc(int i, int j, int P1[MAX][MAX])
{
	if (i) P1[i][j] += P1[i - 1][j];
	if (j) P1[i][j] += P1[i][j - 1];
	if (i && j) P1[i][j] -= P1[i - 1][j - 1];
}

int get1(int x1, int y1, int x2, int y2)
{
	int res = P1[x2][y2];
	if (x1) res -= P1[x1 - 1][y2];
	if (y1) res -= P1[x2][y1 - 1];

	if (x1 && y1) res += P1[x1 - 1][y1 - 1];
	return res;
}

int get2(int x1, int y1, int x2, int y2)
{
	int res = P2[x2][y2];
	if (x1) res -= P2[x1 - 1][y2];
	res -= P2[x2][y1];

	if (x1) res += P2[x1 - 1][y1];
	return res;
}

int get3(int x1, int y1, int x2, int y2)
{
	int res = P3[x2][y2];
	res -= P3[x1][y2];
	if (y1) res -= P3[x2][y1 - 1];

	if (y1) res += P3[x1][y1 - 1];
	return res;
}

void print(int n, int m, int P[MAX][MAX])
{
	FOR(i, 0, n)
	{
		FOR(j, 0, m) cout << P[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	FOR(i, 0, n)
	{
		cin >> A[i];
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			P1[i][j] = A[i][j] == '1';
			recalc(i, j, P1);
		}
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (j && A[i][j] == A[i][j - 1] && A[i][j] == '1')
			{
				P2[i][j] = 1;
			}
			
			recalc(i, j, P2);
		}
	}

	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (i && A[i][j] == A[i - 1][j] && A[i][j] == '1')
			{
				P3[i][j] = 1;
			}

			recalc(i, j, P3);
		}
	}

	//print(n,m,P1);
	//cout << endl;
	//print(n, m, P2);
	//cout << endl;
	//print(n, m, P3);

	FOR(i, 0, q)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x1--;
		y1--;
		x2--;
		y2--;

		int p1 = get1(x1, y1, x2, y2);
		int p2 = get2(x1, y1, x2, y2);
		int p3 = get3(x1, y1, x2, y2);
		
		//cout <<"!!" << p1 << " " << p2 << " " << p3 << endl;
		cout << p1 - (p2 + p3) << endl;
	}
}