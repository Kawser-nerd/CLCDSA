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

const int MOD = 1000003;
char buf[1100000];
int64 z2[110][110][110][110], z[110][110], f[1100000], f1[1100000];

int64 rec2(int len1, int len2, int place, int need) {
	if (need < 0)
		return 0;
	if (len1 == 0)
		return len2 == 0 && need == 0 ? 1 : 0;
	if (z2[len1][len2][place][need] != -1)
		return z2[len1][len2][place][need];

	int64 res = 0;
	int nplace = place, nneed = need - 2;
	if (place) {
		nplace = place - 1;
		nneed = need - 1;
	}
		
	res = rec2(len1 - 1, len2, nplace, need);
	fore(i, 1, len2 + 1) {
		res += rec2(len1 - 1, len2 - i, nplace, nneed);
		res %= MOD;
	}

	return z2[len1][len2][place][need] = res;
}

int64 C(int n, int k) {
	if (n < k || k < 0 || n < 0)
		return 0;
	if (n >= MOD)
		throw;
	return f[n] * f1[k] % MOD * f1[n - k] % MOD;
}

int64 solve2(int len1, int len2, int place, int need) {
	int64 res = 0;
	for (int i = 0; i <= place; i++) {
		int ost = need - i;
		if (ost < 0 || ost % 2 == 1)
			continue;
		ost /= 2;
		if (ost + i > len2)
			continue;
		res += C(place, i) * C(len1 - place, ost) % MOD * C(i + ost - 1 + len2 - i - ost, len2 - i - ost) % MOD;
		res %= MOD;
	}
	return res;
}

void solve() {
	scanf("%s", buf);

	string s = buf;
	/*
	s = "";
	forn(i, 100) {
		char cur = 'a' + i % 3;
		s += string(4500, cur);
	}
	*/
	int r = 1;
	forn(i, s.size())
		if (i && s[i - 1] != s[i])
			r++;

	sort(all(s));

	vector<pair<char, int> > a;
	forn(i, s.size()) {
		int j = i;
		while (j < (int)s.size() && s[i] == s[j])
			j++;

		a.pb(mp(s[i], j - i));
		i = j - 1;
	}

	memset(z, 0, sizeof(z));
	z[0][1] = 1;

//	memset(z2, -1, sizeof(z2));

	int len = a[0].sc;
	fore(i, 1, a.size()) {
		fore(j, 1, r + 1)
			if (z[i - 1][j])
				fore(t, j + 1, r + 1) {
					z[i][t] += z[i - 1][j] * solve2(len + 1, a[i].sc, j + 1, t - j) % MOD;
					z[i][t] %= MOD;
				}

		len += a[i].sc;
	}

	int64 ans = z[(int)a.size() - 1][r];
	cout << ans << endl;
}

int64 binpow(int64 a, int64 b) {
	int64 res = 1;
	while (b)
		if (b & 1) {
			res = res * a % MOD;
			b--;
		}
		else {
			a = a * a % MOD;
			b >>= 1;
		}

	return res;
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	

	f[0] = 1;
	fore(i, 1, MOD)
		f[i] = f[i - 1] * i % MOD;
	forn(i, MOD) {
		f1[i] = binpow(f[i], MOD - 2);
		if (f1[i] * f[i] % MOD != 1)
			throw;
	}
	/*
	forn(ii, 100) {
		cerr << ii << ' ' << clock() << endl;
		solve();
	}

	cerr << clock() << endl;
	return 0;
	*/
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