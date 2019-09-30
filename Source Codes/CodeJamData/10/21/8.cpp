#define _CRT_SECURE_NO_DEPRECATE

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

char buf[110000];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	gets(buf);

	set<int64> hash;
	forn(i, n) {
		gets(buf);
		string s = buf;

		int64 ha = s[0];
		hash.insert(ha);

		int j = 0;
		ha = 0;
		while (j < (int)s.size()) {
			ha = ha * 313 + s[j++];
			while (j < (int)s.size() && s[j] != '/') {
				ha = ha * 313 + s[j];
				j++;
			}

			hash.insert(ha);
		}
	}

	int ans = 0;
	forn(i, m) {
		gets(buf);
		string s = buf;

		int j = 0;
		int64 ha = 0;
		while (j < (int)s.size()) {
			ha = ha * 313 + s[j++];
			while (j < (int)s.size() && s[j] != '/') {
				ha = ha * 313 + s[j];
				j++;
			}

			if (!hash.count(ha)) {
				ans++;
				hash.insert(ha);
			}
		}
	}

	printf("%d", ans);
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

		puts("");
	}
	
	return 0;
}