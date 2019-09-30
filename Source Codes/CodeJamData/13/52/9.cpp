#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <emmintrin.h>

using namespace std;

#define FORE(it,c)  for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)    memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S          size()
#define LL          long long
#define ULL        unsigned long long
#define LD          long double
#define MP          make_pair
#define X          first
#define Y          second
#define VC          vector
#define PII        pair <int, int>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

int bsol[2000];
int sol[2000];
double bv;
int x[2000];
int y[2000];
int n;

const LD EPS = 1e-9;

bool online(int p1, int p2, LD xx, LD yy) {
	// DB("online");
	LD x1 = min(x[p1], x[p2]);
	LD x2 = max(x[p1], x[p2]);
	LD y1 = min(y[p1], y[p2]);
	LD y2 = max(y[p1], y[p2]);
	return xx >= x1 - EPS && xx <= x2 + EPS && yy >= y1 - EPS && yy <= y2 + EPS;
}

#define PDD pair < LD, LD >
PDD intersect(int p1, int p2, int r1, int r2) {
	// DB("int");
	LL A1 = y[p2] - y[p1];
	LL B1 = x[p1] - x[p2];
	LL C1 = A1 * x[p1] + B1 * y[p1];
	
	LL A2 = y[r2] - y[r1];
	LL B2 = x[r1] - x[r2];
	LL C2 = A2 * x[r1] + B2 * y[r1];
	
	LL det = A1 * B2 - A2 * B1;
	if (det == 0) {
		LD x1 = min(x[p1], x[p2]);
		LD x2 = max(x[p1], x[p2]);
		LD y1 = min(y[p1], y[p2]);
		LD y2 = max(y[p1], y[p2]);
		LD u1 = min(x[r1], x[r2]);
		LD u2 = max(x[r1], x[r2]);
		LD v1 = min(y[r1], y[r2]);
		LD v2 = max(y[r1], y[r2]);
		if (max(x1,u1) <= min(x2,u2) && max(y1,v1) <= min(y2,v2)) return MP(max(x1,u1), max(y1, v1));
		return MP(-1e9, -1e9);
	}
	
	return MP((LD)(B2 * C1 - B1 * C2) / det, (LD)(A1 * C2 - A2 * C1) / det);
}

bool valid(int p1, int p2) {
	PDD p = intersect(sol[p1], sol[(p1+1)%n], sol[p2], sol[(p2+1)%n]);
	if (p.X < -1e8) return true;
	if (online(sol[p1], sol[(p1+1)%n], p.X, p.Y) && online(sol[p2], sol[(p2+1)%n], p.X, p.Y)) return false;
	return true;
}

LD area() {
	LL rv = 0;
	REP(i, n) {
		LL x1 = x[sol[i]] - x[sol[0]];
		LL x2 = x[sol[(i+1)%n]] - x[sol[0]];
		LL y1 = y[sol[i]] - y[sol[0]];
		LL y2 = y[sol[(i+1)%n]] - y[sol[0]];
		rv += x1 * y2 - x2 * y1;
	}
	return abs(rv/2.0);
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		cin >> n;
		REP(i, n) cin >> x[i] >> y[i];
		REP(i, n) sol[i] = i;
		// DB(n);
		bv = 0;
		do {
			bool ok = true;
			LD av;
			REP(i, n) REP(j, n-3) {
				int p1 = i;
				int p2 = (i+j+2) % n;
				ok &= valid(p1, p2);
				if (!ok) goto next;
			}
			// print(VI(sol, sol+n));
			if (!ok) continue;
			av = area();
			// DB(av);
			if (av > bv) {
				bv = av;
				REP(i, n) bsol[i] = sol[i];
			}
			next: ;
		} while (next_permutation(sol+1,sol+n));
		printf("Case #%d:", atc);
		REP(i, n) cout << " " << bsol[i];
		cout << endl;
	}
	return 0;
}