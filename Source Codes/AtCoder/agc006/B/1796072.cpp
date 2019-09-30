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

const int MAX = 200000 + 47;

int A[MAX];
set<int> sett;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

	int n, x;
	cin >> n >> x;

	int sz = 2 * n - 1;
	if (x == 1 || x == sz)
	{
		cout << "No" << endl;
		return 0;
	}

	n--;
	A[n] = x;
	sett.insert(x);

	A[n - 1] = x - 1;
	sett.insert(x - 1);

	A[n + 1] = x + 1;
	sett.insert(x + 1);

	if (x + 2 <= sz)
	{
		A[n - 2] = x + 2;
		sett.insert(x + 2);
	}

	if (x - 2 >= 1)
	{
		A[n + 2] = x - 2;
		sett.insert(x - 2);
	}

	int p = 1;
	FOR(i, 0, sz)
	{
		if (A[i]) continue;
		while (sett.find(p) != sett.end()) p++;
		A[i] = p;
		p++;
	}

	cout << "Yes" << endl;
	FOR(i, 0, sz)
	{
		cout << A[i] << "\n";
	}
}