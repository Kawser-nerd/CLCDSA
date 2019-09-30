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

LL getUnion(LL a, LL b, LL c, LL d)
{
	LL r = min(d, b) - max(a, c) + 1;
	LL com = max(r, 0LL);
	return b - a + 1 + d - c + 1 - com;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	
	LL a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << 1 << endl;
		return 0;
	}

	int p = -1;
	FOR(i, 0, 62)
	{
		if ((a >> i) == (b >> i))
		{
			p = i;
			break;
		}
	}

	p--;
	LL mask = (1LL << p) - 1;
	LL c = a | mask;

	//cout << "!" << a << " " << c << endl;
	LL ans = c - a + 1;
	LL tmp = b & mask;
	int k = 0;
	while ((tmp >> k) != 0) k++;
	tmp = (1LL << k) - 1;

	LL l1 = c + 1;
	LL r1 = b | tmp;
	LL l2 = a | (1LL << p);
	LL r2 = l2 | mask;

	//cout << l1 << " " << r1 << " - " << l2 << " " << r2 << endl;
	//cout << getUnion(l1, r1, l2, r2) << endl;
	ans += getUnion(l1, r1, l2, r2);

	cout << ans << endl;
}