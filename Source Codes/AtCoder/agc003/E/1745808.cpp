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
const int MOD = 1000 * 1000 * 1000 + 7;

LL T[MAX];
LL A[MAX];
LL Q[MAX];
int sz;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	cin >> n >> q;
	if (q == 0)
	{
		FOR(i, 0, n) cout << "1\n";
		return 0;
	}

	FOR(i, 0, q)
	{
		LL a;
		cin >> a;
		while (sz && Q[sz - 1] >= a) sz--;
		Q[sz++] = a;
	}
	
	//cout << sz << endl;
	//FOR(i, 0, sz) cout << Q[i] << " ";
	//cout << endl;
	T[sz - 1] = 1;
	LL cnt = min(Q[0], (LL)n);

	RFOR(i, sz, 0)
	{
		LL a = Q[i];
		while (1)
		{
			int ind = lower_bound(Q, Q + sz, a) - Q;
			if (ind == 0) break;
			ind--;

			T[ind] += T[i] * (a / Q[ind]);
			a %= Q[ind];
		}

		A[cnt - 1] += (a / cnt) * T[i];
		if (a % cnt) A[a % cnt - 1] += T[i];
	}

	//FOR(i, 0, n) cout << A[i] << " ";
	//cout << endl;
	RFOR(i, n - 1, 0)
	{
		A[i] += A[i + 1];
	}

	FOR(i, 0, n) cout << A[i] << " \n";
	cout << endl;
}