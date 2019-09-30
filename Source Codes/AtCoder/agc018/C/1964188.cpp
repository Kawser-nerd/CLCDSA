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

const int MAX = 1000 * 100 + 47;
struct Item
{
	int a, b, c;
	bool operator <(const Item& x) const
	{
		return b - c < x.b - x.c;
	}
};

Item A[MAX];
LL P[MAX];
LL S[MAX];
multiset<LL> SS;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	int n = x + y + z;
	FOR(i, 0, n) cin >> A[i].a >> A[i].b >> A[i].c;
	
	sort(A, A + n);
	LL cur = 0;
	FOR(i, 0, n)
	{
		SS.insert(A[i].c - A[i].a);
		cur += A[i].c - A[i].a;
		if (SZ(SS) > z)
		{
			cur -= *SS.begin();
			SS.erase(SS.begin());
		}

		if (SZ(SS) != z)
		{
			P[i] = -LINF;
			continue;
		}

		P[i] = cur;
	}

	cur = 0;
	SS.clear();
	RFOR(i, n, 0)
	{
		SS.insert(A[i].b - A[i].a);
		cur += A[i].b - A[i].a;
		if (SZ(SS) > y)
		{
			cur -= *SS.begin();
			SS.erase(SS.begin());
		}

		if (SZ(SS) != y)
		{
			S[i] = -LINF;
			continue;
		}

		S[i] = cur;
	}

	LL ans = -LINF;
	LL s = 0;
	FOR(i, 0, n) s += A[i].a;

	FOR(i, 0, n - 1)
	{
		if (P[i] == -LINF || S[i + 1] == -LINF) continue;

		ans = max(ans, s + P[i] + S[i + 1]);
	}

	cout << ans << endl;
}