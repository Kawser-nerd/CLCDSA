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
#define DB(a)		cout << #a << ": " << a << endl

void print(VI v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
void print(VS v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

int x[202][202];
int n;
int get(int i, int j) {
	if (i < 0 || i >= 2 * n - 1 || j < 0 || j >= 2 * n - 1) return -1;
	return x[i][j];
}

int vv[4];
int check(int x0, int x1) {
	return x0 == -1 || x1 == -1 || x0 == x1;
}

int hok[200];
int vok[200];

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		cin >> n;
		memset(x, -1, sizeof x);
		REP(i, 2 * n - 1) {
			int l = min(i + 1, 2 * n - 1 - i);
			REP(j, l) cin >> x[i][j + j + n - l];
		}
		int rv = 1 << 20;
		//REP(i, 2 * n - 1) print(VI(x[i], x[i] + 2 * n - 1));
		REP(z, 2 * n - 1) {
			hok[z] = 1;
			vok[z] = 1;
			REP(i, 2 * n - 1) REP(j, 2 * n - 1) hok[z] &= check(get(i, j), get(i, z + z - j));
			REP(i, 2 * n - 1) REP(j, 2 * n - 1) vok[z] &= check(get(i, j), get(z + z - i, j));
			//DB(hok[z]);
			//DB(vok[z]);
		}
		REP(i, 2 * n - 1) REP(j, 2 * n - 1) if (hok[i] && vok[j]) {
			int d = abs(i - n + 1) + abs(j - n + 1);
			rv <?= (n + d) * (n + d) - n * n;
		}
		printf("Case #%d: %d\n", atc, rv);
	}
}
