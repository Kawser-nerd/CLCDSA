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

const int MAX = 1000 * 1000 + 47;

int SH[MAX];
int R[MAX];
int L[MAX];
int H[MAX];

string s, t;

void imp()
{
	cout << -1 << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n >> s >> t;
	if (s == t)
	{
		cout << 0 << endl;
		return 0;
	}

	FOR(i, 0, n)
	{
		R[i] = -1;
	}
	int p = n - 1;

	RFOR(i, n, 0)
	{
		while (p != -1 && t[i] != s[p]) p--;
		if (p == -1) imp();
		L[p] = i;
		R[p] = max(i, R[p]);
		if (i == p) p--;
	}

	int sh = 0, add = 0;
	int ans = 0;
	RFOR(i, n, 0)
	{
		H[i + sh] = -add;
		if (R[i] == -1)
		{
			continue;
		}

		ans = max(ans, H[R[i] + sh] + add + 1);
		sh++;
		add++;
	}

	//FOR(i, 0, n)
	//{
	//	cout << R[i] << " ";
	//}
	//cout << endl;
	//FOR(i, 0, n)
	//{
	//	cout << H[i] << " ";
	//}
	//cout << endl;
	cout << ans << endl;
}