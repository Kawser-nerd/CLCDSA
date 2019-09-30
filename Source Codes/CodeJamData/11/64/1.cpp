#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

bool check(vector<int> a) {
	forn(i, a.size())
		if (a[i] != -1)
			forn(j, i)
				if (a[j] != -1)
					forn(t, j)
						if (a[t] > a[j] && a[j] > a[i])
							return false;
	return true;
}

int a[110000], n;
map<vector<int>, int> z;
vector<int> ans;

int rec(vector<int> b) {
	if (z.count(b))
		return z[b];

	int res = INF;
	vector<char> u(n);
	forn(i, b.size())
		if (b[i] != -1)
			u[b[i]] = true;

	if (u[0])
		return z[b] = 0;

	forn(i, n)
		if (b[i] == -1) {
			int cur = -INF;
			forn(j, n)
				if (!u[j]) {
					b[i] = j;
					if (!check(b))
						continue;
					cur = max(cur, rec(b));
					b[i] = -1;
				}
			res = min(cur + 1, res);
		}

	return z[b] = res;
}

void recwrite(vector<int> b) {
	int res = z[b], cnt = 0;
	vector<char> u(n);
	forn(i, b.size())
		if (b[i] != -1) {
			u[b[i]] = true;
			cnt++;
		}

	if (u[0]) {
		if (cnt != n)
			throw;
		if (ans.empty())
			ans = b;
		else
			ans = max(ans, b);
		return;
	}		

	int i = a[cnt];
	if (b[i] == -1) {
		int cur = -INF;
		ford(j, n)
			if (!u[j]) {
				b[i] = j;
				if (!check(b))
					continue;
				if (res == rec(b) + 1) {
					recwrite(b);
				}
				b[i] = -1;
			}
	}
	else
		throw;

	return;

}

void solve() {
	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}

	if (n == 1) {
		puts("1");
		return;
	}

	vector<int> b(n, -1);
	if (rec(b) != n)
		throw;

	ans.clear();
	recwrite(b);

	forn(i, ans.size())
		printf(i ? " %d" : "%d", ans[i] + 1);
	puts("");
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}