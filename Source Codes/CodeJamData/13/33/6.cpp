#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(t, v) memset((t), (v), sizeof(t))
#define w(a) #a << ": " << (a) << "  "

#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define dwn(i, n) for (int i = (n); --i >= 0;)
#define repr(i, l, r) for (int i = (l), _##i = (r); i < _##i; ++i)
#define dwnr(i, l, r) for (int i = (r), _##i = (l); --i >= _##i;)
#define repi(i, a) for (__typeof((a).begin()) i = (a).begin(), _##i=(a).end(); i != _##i; ++i)
#define dwni(i, a) for (__typeof((a).rbegin()) i = (a).rbegin(), _##i=(a).rend(); i != _##i; ++i)

struct attack {
	int time;
	int st, end;
	int strength;
	attack(int t, int s, int e, int h) {
		time = t;
		st = s;
		end = e;
		strength = h;
	}
	bool operator<(const attack& oth) const {
		return time < oth.time;
	}
};

int dat[1 << 22];
int mindat[1 << 22];
int ql, qr, qv;
int query(int p, int l, int r, int v = 0) {
	if (qr <= l) return 1 << 30;
	if (ql >= r) return 1 << 30;
	v = max(v, dat[p]);
	if (l >= ql && r <= qr) {
		return max(v, mindat[p]);
	}
	int m = (l + r) / 2;
	return min(query(p * 2, l, m, v), query(p * 2 + 1, m, r, v));
}
void update(int p, int l, int r, int v = 0) {
//	cout << p << ' ' << l << ' ' << r << endl;
	if (qr <= l) return;
	if (ql >= r) return;
	v = max(v, dat[p]);
	if (l >= ql && r <= qr) {
		mindat[p] = dat[p] = max(dat[p], qv);
		if (p < (1 << 21)) {
			mindat[p] = max(mindat[p], min(mindat[p * 2], mindat[p * 2 + 1]));
		}
		mindat[p] = max(mindat[p], v);
		return;
	}
	int m = (l + r) / 2;
	update(p * 2, l, m);
	update(p * 2 + 1, m, r);
	mindat[p] = min(mindat[p * 2], mindat[p * 2 + 1]);
	mindat[p] = max(mindat[p], v);
}

//int ndat[2000];
//
//void update() {
//	repr (i, ql, qr) {
//		ndat[i] = max(ndat[i], qv);
//	}
//}
//int query() {
//	return *min_element(ndat + ql, ndat + qr);
//}

vector<attack> attacks;
vector<int> pos;

void go() {
//	memset(ndat, 0, sizeof(ndat));
	
	attacks.clear();
	pos.clear();
	memset(dat, 0, sizeof(dat));
	memset(mindat, 0, sizeof(mindat));
	
	int N;
	cin >> N;
	rep (i, N) {
		int t;
		int k;
		int s, e;
		int h;
		int dt;
		int dp;
		int dh;
		cin >> t >> k >> s >> e >> h >> dt >> dp >> dh;
		rep (i, k) {
			attacks.push_back(attack(t, s, e, h));
			pos.push_back(s);
			pos.push_back(e);
			t += dt;
			s += dp;
			e += dp;
			h += dh;
		}
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	sort(attacks.begin(), attacks.end());
	rep (i, attacks.size()) {		
		attacks[i].st = lower_bound(pos.begin(), pos.end(), attacks[i].st) - pos.begin();
		attacks[i].end = lower_bound(pos.begin(), pos.end(), attacks[i].end) - pos.begin();
//		cout << attacks[i].time << ' ' << attacks[i].st << ' ' << attacks[i].end << ' ' << attacks[i].strength << endl;
	}
	int ans = 0;
	int i = 0;
	while (i < attacks.size()) {
		int ct = attacks[i].time;
		int j = i;
		while (j < attacks.size() && ct == attacks[j].time) {
			ql = attacks[j].st;
			qr = attacks[j].end;
			if (query(1, 0, 1 << 21) < attacks[j].strength) {
//				cout << "success " << ct << ' ' << query(1, 0, 1 << 21) << ' ' << attacks[j].strength << endl;
				ans++;
			}
//			if (query(1, 0, 1 << 21) != query()) {
//				cout << "error: " <<  ct << ' ' << query(1, 0, 1 << 21) << ' ' << query() << ' ' << attacks[j].strength << endl;
//			}
			j++;
		}
		j = i;
		while (j < attacks.size() && ct == attacks[j].time) {
			ql = attacks[j].st;
			qr = attacks[j].end;
			qv = attacks[j].strength;
			update(1, 0, 1 << 21);
//			update();
			j++;
		}
		i = j;
	}
	cout << ans;
}

int main() { freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ": ";
		go();
		cout << '\n';
	}
}
