#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

int x0[1000],x1[1000],y0[1000],y1[1000];
int vs[1000];

int n;
int bx, by;

int overlap(int ax0, int ax1, int ay0, int ay1) {
	return max(ax0, ay0) <= min(ax1, ay1);
}

int overlap(int r, int tx0, int ty0, int tx1, int ty1) {
	return overlap(tx0, tx1, x0[r], x1[r]) && overlap(ty0, ty1, y0[r], y1[r]);
}

void go(int x) {
	if (vs[x]) return;
	vs[x] = 1;
	bx >?= x1[x];
	by >?= y1[x];
	REP(i, n) {
		if (overlap(i, x0[x] - 1, y0[x], x1[x], y1[x] + 1) || overlap(i, x0[x], y0[x] - 1, x1[x] + 1, y1[x]))
			go(i);
	}
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		cin >> n;
		REP(i, n) {
			cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
		}
		int no = 0;
		REP(i, n) {
			ZERO(vs);
			bx = 0, by = 0;
			go(i);
			no >?= (bx - x0[i]) + (by - y0[i]) + 1;
		}

		printf("Case #%d: %d\n", atc, no);
	}
}