#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

class card {
public:
	int c, s, t, id;
};

card t[100];

bool operator < (card a, card b) {
	if (a.t != b.t)
		re a.t > b.t;
	if (a.s != b.s)
		re a.s > b.s;
	if (a.c != b.c)
		re a.c > b.c;
	re a.id < b.id;
}

void apply(set<card> &cur, card x, int &ans, int &ct, int &cp, int flag) {
	cur.erase(x);
	ct += x.t - 1;
	ans += x.s;
	int o = x.c;
	while (cp < n + m && o) {
		card tmp = t[cp];
		if (flag)
			tmp.s = 0;
		cur.insert(tmp);
		cp++;
		o--;
	}
}

int check(set<card> s, int ep, int cp, int ct) {
	set<card> cur;
	while (!s.empty()) {
		card tmp = *s.begin();
		s.erase(tmp);
		tmp.s = 0;
		cur.insert(tmp);
	}

	int ans = 0;
	while (1) {
		if (cp >= ep)
			re 1;
		if (ct == 0 || cur.empty())
			re 0;
		card x = *cur.begin();
		apply(cur, x, ans, ct, cp, 1);
	}
	re 0;
}

int getsum(set<card> cur, int ct) {
	int ans = 0;
	while (1) {
		if (ct == 0 || cur.empty())
			break;
		card x = *cur.begin();
		cur.erase(x);
		ct += x.t - 1;
		ans += x.s;
	}
	re ans;
}

int getans(set<card> cur, int ep, int cp) {
	if (!check(cur, ep, n, 1))
		re 0;

	int ans = 0;
	int ct = 1;

	while (1) {
		if (cp >= ep)
			re ans + getsum(cur, ct);
		if (ct == 0 || cur.empty())
			re 0;

		while (1) {
			if (cp >= ep)
				re ans + getsum(cur, ct);
			if (ct == 0)
				re 0;
			card x = *cur.begin();
			if (x.t == 0)
				break;
			apply(cur, x, ans, ct, cp, 0);
		}

		set<card>::iterator it = cur.begin();
		while (it != cur.end() && it->c == 0)
			it++;
		if (it == cur.end())
			re 0;

		card x = *it;
		if (x.c == 1) {
			set<card> tmp = cur;
			cur.erase(x);
			if (check(cur, ep, cp, ct - 1) == 0) {
				while (it != cur.end() && it->c == 1)
					it++;
				if (it == cur.end())
					re 0;
			}
		}

		cur.erase(x);
		ct += x.t - 1;
		ans += x.s;
		int o = x.c;
		while (cp < n + m && o) {
			cur.insert(t[cp]);
			cp++;
			o--;
		}
	}
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);
		cin >> n;
		set<card> cur;
		rep(i, n) {
			cin >> t[i].c >> t[i].s >> t[i].t;
			t[i].id = i;
			cur.insert(t[i]);
		}
		cin >> m;
		rep(i, m) {
			cin >> t[i + n].c >> t[i + n].s >> t[i + n].t;
			t[i + n].id = i + n;
		}

		int ans = 0;
		for (int o = n; o <= n + m; o++)
			ans = max(ans, getans(cur, o, n));
		cout << ans << endl;
	}

	re 0;
}

