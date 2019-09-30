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
const int MOD = 1000 * 1000 + 3;

int A[MAX][MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int H, W, h, w;
	int x = 1000 * 1000 * 1000 - 1;
	int y = -1000 * 1000 * 1000;

	cin >> H >> W >> h >> w;
	if (H % h == 0 && W % w == 0)
	{
		cout << "No" << endl;
		return 0;
	}

	if (W % w != 0)
	{
		FOR(i, 0, H)
		{
			if (i % h != 0) continue;

			FOR(j, 0, W)
			{
				if (j % w == 0) A[i][j] = x;
				if (j % w == w - 1) A[i][j] = y;
			}
		}
	}
	else
	{
		FOR(j, 0, W)
		{
			if (j % w != 0) continue;

			FOR(i, 0, H)
			{
				if (i % h == 0) A[i][j] = x;
				if (i % h == h - 1) A[i][j] = y;
			}
		}
	}

	cout << "Yes" << endl;
	FOR(i, 0, H)
	{
		FOR(j, 0, W)
		{
			cout << A[i][j] << " ";
		}

		cout << endl;
	}
}