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
const int MAX = 1000 * 1000 + 47;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	double d0, x;
	cin >> n >> d0 >> x;

	double ans = 0;
	RFOR(k, n + 1, 1)
	{
		//cout << d0 << " " << x << endl;
		ans += (2 * d0 + x * (2 * k - 1)) * k / (2.0 * k);
		if (k == 1) break;

		double x1 = (2 * x + k * x) / k;
		double d1 = (2 * (k + 1) * d0 + 5 * x) / (2.0 * k);
		x = x1;
		d0 = d1;
	}

	cout << fixed << setprecision(12) << ans << endl;
}