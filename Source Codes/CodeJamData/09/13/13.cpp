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
#define FORE(i,a)   for(__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define LD          long double
#define MP          make_pair
#define PII         pair<int, int>
#define X           first
#define Y           second
#define VC          vector
#define VI          VC<int>
#define VVI         VC< VI >
#define VS          VC<string>
#define VPII        VC< PII >
#define DB(a)       cerr << #a << ": " << a << endl;

void print(VI v) {cout << "[";if (v.S) cout << v[0];FOR(i, 1, v.S) cout << ", " << v[i];cout << "]\n";}
void print(VS v) {cout << "[";if (v.S) cout << v[0];FOR(i, 1, v.S) cout << ", " << v[i];cout << "]\n";}
void print(VVI v) {cout << "[ ---";if (v.S) cout << " ", print(v[0]);FOR(i, 1, v.S) cout << " ", print(v[i]);	cout << "--- ]\n";}
void print(PII p) {cout << "{" << p.X << ", " << p.Y << "}";}
void print(VPII v) {cout << "[";if (v.S) print(v[0]);FOR(i, 1, v.S)  cout << ", ", print(v[i]);cout << "]\n";}

template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

#define MAX 100000
LD dp[MAX][41];
LD bb[41][41];
LD tr[41][41][41][41];

int N, C;
LD go(int a, int d, int b, int c) {
	LD &rv = tr[a][d][b][c];
	if (rv > -0.5) return rv;
	if (a == 0) return rv = (b == c) ? 1.0 : 0.0;
	if (c > b) return rv = 0;
	return rv = go(a - 1, d - 1, b, c) * (LD)(d - b) / d + go(a - 1, d - 1, b - 1, c) * (LD)b / d;
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		ZERO(dp);
		cin >> C >> N;
		
		LD el = 1.0;
		LD ev = 0;
		dp[0][C] = 1.0;
		
		REP(i, 41) REP(j, 41) REP(k, 41) REP(w, 41) tr[i][w][j][k] = -0.5;
		REP(i, C + 1) REP(j, i + 1) go(N, C, i, j);
		//DB(tr[N][C][2][0]);
		//DB(tr[N][C][1][0]);
					
		REP(i, 41) REP(j, 41) bb[i][j] =tr[N][C][i][j];
		
		REP(i, MAX) {
			if (el < 1e-16) break;
			el -= dp[i][0];
			ev += i * dp[i][0];
			FOR(j, 1, C + 1) REP(k, j + 1) dp[i + 1][k] += dp[i][j] * bb[j][k];
		}
		
		printf("Case #%d: %.8Lf", atc, ev);
		printf("\n");
	}
}
