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

int g[30][30], u[30], n;
bool op[30][30];
char buf[110000];

void add(string &s, char x) {
	if (s.empty()) {
		s += x;
		u[x - 'A']++;
		return;
	}
	char la = s[s.size() - 1];
	if (g[la - 'A'][x - 'A'] != -1) {
		char ne = g[la - 'A'][x - 'A'];
		u[la - 'A']--;
		s.erase(s.size() - 1);
		return add(s, ne);
	}
	forn(i, 26)
		if (u[i] && op[i][x - 'A']) {
			s.clear();
			forn(j, 26)
				u[j] = 0;
			return;
		}
	s += x;
	u[x - 'A']++;
}

void solve() {
	int k;
	scanf("%d", &k);
	memset(g, -1, sizeof(g));
	memset(op, 0, sizeof(op));
	forn(i, k) {
		scanf("%s", buf);
		string s = buf;
		g[s[0] - 'A'][s[1] - 'A'] = g[s[1] - 'A'][s[0] - 'A'] = s[2];
	}

	scanf("%d", &k);
	forn(i, k) {
		scanf("%s", buf);
		op[buf[0] - 'A'][buf[1] - 'A'] = op[buf[1] - 'A'][buf[0] - 'A'] = true;
	}

	scanf("%d", &n);
	scanf("%s", buf);
	string s = buf;
	memset(u, 0, sizeof(u));
	string c = "";
	forn(i, n)
		add(c, s[i]);

	printf("[");
	forn(i, c.size())
		printf(i ? ", %c" : "%c", c[i]);
	puts("]");
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