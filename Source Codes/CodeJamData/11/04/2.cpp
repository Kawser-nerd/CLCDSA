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

int a[1100];
bool u[1100];

int one(vector<int> a) {
	int tt = 0;
	while (true) {
		vector<int> p;
		forn(i, a.size())
			if (a[i] != i)
				p.pb(i);

		if (p.empty())
			return tt;

		tt++;

		random_shuffle(all(p));

		int cnt = 0;
		forn(i, a.size())
			if (a[i] != i)
				a[i] = p[cnt++];
	}
}

double tupo(vector<int> a) {
	double res = 0;
	forn(i, 1000)
		res += one(a);

	return res / 1000;
}

void solve() {
	memset(u, 0, sizeof(u));

	int n;
	scanf("%d", &n);
	forn(i, n) {
		scanf("%d", &a[i]);
		a[i]--;
	}
/*
	vector<int> b(a, a + n);
	cout << tupo(b) << endl;
*/
	int ans = 0;
	forn(i, n) 
		if (!u[i]) {
			int j = i, cnt = 0;
			while (!u[j]) {
				u[j] = true;
				cnt++;
				j = a[j];
			}

			if (cnt == 1)
				continue;

			ans += cnt;
		}

	printf("%d.000000\n", ans);
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);
		solve();
	}
	
	return 0;
}