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

const int MAX = 1000 * 100 + 47;

int A[MAX];
LL P[MAX];
LL N[MAX];
int n, k;

LL getN(int l, int r)
{
	if (r < 0) return 0;
	if (l >= n) return 0;
	LL res = N[r];
	if (l) res -= N[l - 1];
	return res;
}

LL getP(int l, int r)
{
	if (r < 0) return 0;
	if (l >= n) return 0;
	LL res = P[r];
	if (l) res -= P[l - 1];
	return res;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	FOR(i, 0, n)
	{
		cin >> A[i];
	}

	FOR(i, 0, n)
	{
		if (i)
		{
			P[i] = P[i - 1];
			N[i] = N[i - 1];
		}

		if (A[i] > 0) P[i] += A[i];
		N[i] += A[i];
	}

	LL ans = -LINF;
	FOR(l, 0, n)
	{
		int r = l + k - 1;
		if (r >= n) break;
		LL tmp = getP(0, l - 1) + getP(r + 1, n - 1) + getN(l, r);
		ans = max(tmp, ans);
		tmp = getP(0, l - 1) + getP(r + 1, n - 1);
		ans = max(tmp, ans);
	}

	cout << ans << endl;
}