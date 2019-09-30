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

const int MAX = 400 + 47;
const int MAX1 = 1000 * 100 + 47;

int A[MAX1];
int B[MAX1];
int U[MAX][MAX];
int BAD[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m)
	{
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}

	FOR(i, 0, n)
	{
		U[i][i] = 1;
		RFOR(j, m, 0)
		{
			int a = A[j];
			int b = B[j];
			if (U[i][a] && U[i][b])
			{
				BAD[i] = 1;
				break;
			}

			if (U[i][a])
			{
				U[i][b] = 1;
				continue;
			}

			if (U[i][b]) U[i][a] = 1;
		}
	}

	int ans = 0;
	FOR(i, 0, n)
	{
		if (BAD[i]) continue;

		FOR(j, i + 1, n)
		{
			if (BAD[j]) continue;
			bool ok = true;
			FOR(k, 0, n)
			{
				if (U[i][k] && U[j][k])
				{
					ok = false;
					break;
				}
			}

			if (ok) ans++;
		}
	}

	cout << ans << endl;
}