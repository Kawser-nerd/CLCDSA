#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define VI          VC<int>
#define VS          VC<string>

void print(VI v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
void print(VS v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

int mm[11][1024][11];
int tk[11][1024];
int ms[1024];
int n;

#define MX (1 << 29)

int go(int lv, int p, int b) {
	int &rv = mm[lv][p][b];
	if (rv != -1) return rv;
	rv = MX;
	if (lv == 0) return rv = (b >= n - ms[p]) ? 0 : MX;
	rv <?= go(lv - 1, 2 * p, b) + go(lv - 1, 2 * p + 1, b);
	rv <?= go(lv - 1, 2 * p, b + 1) + go(lv -1, 2 * p + 1, b + 1) + tk[lv][p];
	return rv;
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		memset(mm, -1, sizeof mm);
		cin >> n;
		REP(i, 1 << n) cin >> ms[i];
		FOR(i, 1, n + 1) REP(j, 1 << (n - i)) cin >> tk[i][j];
		printf("Case #%d: %d \n", atc, go(n, 0, 0));
	}
}