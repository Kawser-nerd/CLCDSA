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

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 100;
LL n, a, b, c, d;

bool ok(LL from, LL to)
{
	if (from > to) return false;
	if (to < 0) return false;
	if (from > n) return false;

	return true;
}

void yes()
{
	cout << "YES" << endl;
	exit(0);
}

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
	
	cin >> n >> a >> b >> c >> d;

	if (c + d == 0)
	{
		if (a == b) yes();
		no();
	}

	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	n--;

	LL to = (b - a + n * d) / (c + d);
	LL from = (b - a + n* c + (c + d - 1)) / (c + d);

	//cout << from << " " << to << endl;
	if (ok(from, to)) yes();
	no();
}