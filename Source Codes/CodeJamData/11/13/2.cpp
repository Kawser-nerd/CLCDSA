#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

struct card { int c, s, t; } a[88];
int n, m;
bool u[88];
int best;
set<ll> U;
ll h[88];

void go(int n, int s, int t) {
	best = max(best, s);
	if (t == 0) return;
	ll hsh = 0;
	REP (i, n) if (u[i]) hsh ^= h[i];
	hsh = hsh * 23429387423 + s;
	if (U.count(hsh)) return;
	U.insert(hsh);
	vi b;
	REP (i, n) if (!u[i] && a[i].t > 0) {
		b.pb(i);
		u[i] = true;
		s += a[i].s;
		t += a[i].t - 1;
		n = min(m, n + a[i].c);
	}
	best = max(best, s);
	int q[3] = {-1, -1, -1};
	REP (i, n) if (!u[i]) {
		int z = a[i].c;
		if (q[z] < 0 || a[q[z]].s < a[i].s)
			q[z] = i;
	}
	REP (j, 3) REP (i, j)
		if (q[i] >= 0 && q[j] >= 0 && a[q[i]].s <= a[q[j]].s)
			q[i] = -1;
	for (int i : q) if (~i) {
		u[i] = true;
		go(min(m, n + a[i].c), s + a[i].s, t - 1);
		u[i] = false;
	}
	for (int i : b) u[i] = false;
}

void run() {
	U.clear();
	REP (i, 88) REP (j, 10) h[i] = h[i] * 100 ^ rand();
	cin >> n;
	REP (i, n) cin >> a[i].c >> a[i].s >> a[i].t;
	cin >> m;
	m += n;
	FOR (i, n, m) cin >> a[i].c >> a[i].s >> a[i].t;
	best = 0;
	CL(u, false);
	go(n, 0, 1);
	cout << best << endl;
}

int main(){
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	cout.precision(12);
	cout.setf(ios::fixed);
	int a = 0, b = 0;
	for(cin >> b; a++ < b ; run()) 
		printf("Case #%d: ", a);
	return 0;
}
