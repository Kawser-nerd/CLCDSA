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

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX = 20 + 47;

int A[MAX][MAX];
int B[MAX][MAX];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		FOR(j, 0, SZ(s)) A[i][j] = s[j] == '#';
	}
	
	int len = n + m - 2;
	FOR(mask, 0, 1 << len)
	{
		FOR(i, 0, n) FOR(j, 0, m) B[i][j] = A[i][j];

		int x = 0, y = 0;
		FOR(k, 0, len + 1)
		{
			if (x >= n || y >= m) break;
			if (B[x][y] == 0) break;
			
			B[x][y] = 0;
			if (mask & (1 << k))
			{
				y++;
				continue;
			}

			x++;
		}

		int cnt = 0;
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				if (B[i][j]) cnt++;
			}
		}

		if (cnt == 0)
		{
			cout << "Possible" << endl;
			return 0;
		}
	}

	cout << "Impossible" << endl;
}