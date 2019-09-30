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

map<int, int> M;
void no()
{
	cout << "No" << endl;
	exit(0);
}

void yes()
{
	cout << "Yes" << endl;
	exit(0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	int n, a, b;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a;
		M[a]++;
	}

	if (SZ(M) > 2) no();
	if (SZ(M) == 1)
	{
		a = M.begin()->first;
		if (2 * a <= n || n - 1 == a) yes();
		no();
	}

	a = M.begin()->first;
	int cnta = M.begin()->second;

	auto it = M.begin();
	it++;
	b = it->first;
	int cntb = it->second;

	if (b - a != 1) no();
	if (cntb == 1)
	{
		if (cnta == a && cnta == b) yes();
		no();
	}
	
	if (b > cnta && cntb >= 2 * (b - cnta)) yes();
	//if (cnta == b - 1 && cnta == a) yes();

	no();
}