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

struct Ev {
	int x, type, who;
	Ev() {}
	Ev(int x, int type, int who): x(x), type(type), who(who) {}
};

bool operator < (const Ev &a, const Ev &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.type < b.type;
}

int n;
string color[1000];
int start[1000], finish[1000];
vii av[1000];
ii coff[1000];
int noff;
int nev;
Ev ev[1000];
bool took[1000];

int doit() {
	nev = 0;
	for (int i = 0; i < noff; i++) {
		ev[nev++] = Ev(coff[i].first, -1, i);
		ev[nev++] = Ev(coff[i].second + 1, 1, i);
	}
	ev[nev++] = Ev(1, 1, -1);
	ev[nev++] = Ev(10001, -1, -1);
	sort(ev, ev + nev);
	memset(took, 0, sizeof(took));
	int cnt = 1;
	set<ii> aux;
	int total = 0;
	for (int i = 0; i < nev; i++) {
		if (ev[i].type == -1) {
			if (ev[i].who == -1) {
				if (cnt) {
					return total;
				}
				else return 1000;
			}
			aux.insert(mp(coff[ev[i].who].second, ev[i].who));
		}
		else {
			if (ev[i].who != -1 && !took[ev[i].who]) continue;
			cnt--;
			if (!cnt) {
				if (!aux.size()) return 1000;
				set<ii>::iterator it = aux.end();
				it--;
				if (coff[it->second].second < ev[i].x) {
					continue;
				}
				cnt++;
				total++;
				took[it->second] = true;
				aux.clear();
			}
		}
	}
	assert(false);
}

int doit(int c1, int c2, int c3) {
	noff = 0;
	for (int i = 0; i < sz(av[c1]); i++) {
		coff[noff++] = av[c1][i];
	}
	for (int i = 0; i < sz(av[c2]); i++) {
		coff[noff++] = av[c2][i];
	}
	for (int i = 0; i < sz(av[c3]); i++) {
		coff[noff++] = av[c3][i];
	}
	return doit();
}

void solve(int it) {
	cin >> n;
	vs clr;
	for (int i = 0; i < n; i++) {
		cin >> color[i] >> start[i] >> finish[i];
		clr.pb(color[i]);
	}
	sort(all(clr));
	clr.erase(unique(all(clr)), clr.end());
	int nc = sz(clr);
	if (nc < 3) nc = 3;
	for (int i = 0; i < 1000; i++) {
		av[i].clear();
	}
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(all(clr), color[i]) - clr.begin();
		av[ind].pb(mp(start[i], finish[i]));
	}
	int ans = 1000;
	for (int i = 0; i < nc; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				ans = min(ans, doit(i, j, k));
			}
		}
	}
	printf("Case #%d: ", it);
	if (ans == 1000) {
		printf("IMPOSSIBLE\n");
	}
	else printf("%d\n", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; it++) {
		fprintf(stderr, "%d\n", it);
		solve(it);
	}
	return 0;
}
