#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef double D;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)((x).size()))

template<class T> T sqr(T x) { return x * x;            }
template<class T> T abs(T x) { return (x > 0) ? x : -x; }

struct P {
	D x, y;

	P() {}
	P(D x, D y): x(x), y(y) {}

	P operator + (P a) { return P(x + a.x, y + a.y); }
	P operator - (P a) { return P(x - a.x, y - a.y); }
	P operator * (D a) { return P(x * a, y * a); }
	D operator * (P a) { return x * a.y - y * a.x;   }
	D operator ^ (P a) { return x * a.x + y * a.y;   }

	D len2() { return sqr(x) + sqr(y); }
	D len()  { return sqrt(len2());    }
	P orth() { return P(y, -x);        }
};

struct L {
	D a, b, c;

	L() {}
	L(D a, D b, D c): a(a), b(b), c(c) {}
	L(P p1, P p2) {
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = -p1.x * a - p1.y * b;
	}
};

struct C {
	P c;
	D r;

	C() {}
	C(P c, D r): c(c), r(r) {}
};

vi e0[600];
int n, k;
vi e1[600];

int d[600];

int doit(int x) {
	memset(d, 63, sizeof(d));
	queue<int> q;
	q.push(x);
	d[x] = 0;
	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (d[cur] > 3) continue;
		cnt++;
		for (int i = 0; i < sz(e1[cur]); i++) {
			if (d[e1[cur][i]] < 1000000000) continue;
			d[e1[cur][i]] = d[cur] + 1;
			q.push(e1[cur][i]);
		}
	}
	return cnt;
}

void solve(int it) {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		e0[i].clear();
		e1[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		e0[a].pb(b);
		e0[b].pb(a);
	}
	bool was[600];
	memset(was, 0, sizeof(was));
	queue<int> q;
	q.push(0);
	was[0] = true;
	ll ans = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < sz(e0[cur]); i++) {
			if (was[e0[cur][i]]) continue;
			was[e0[cur][i]] = true;
			q.push(e0[cur][i]);
			e1[cur].pb(e0[cur][i]);
			e1[e0[cur][i]].pb(cur);
			int cnum = doit(e0[cur][i]);
			cnum -= 2;
			int mul = k - cnum;
			if (mul < 0) mul = 0;
			ans *= mul;
			ans %= 1000000009;
		}
	}
	printf("Case #%d: ", it);
	cout << ans << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; it++) {
		solve(it);
	}
	return 0;
}
