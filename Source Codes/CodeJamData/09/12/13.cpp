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

LL s[30][30];
LL w[30][30];
LL t[30][30];
LL dp[30][30][4];

LL waittime(PII p, LL tt, int dir) {
	LL cc = s[p.X][p.Y] + w[p.X][p.Y];
	LL at = t[p.X][p.Y];
	
	if (dir) at += s[p.X][p.Y];
	LL wt = dir ? w[p.X][p.Y] : s[p.X][p.Y];
	
	at += ((tt - at) / cc) * cc;
	while (at > tt) at -= cc;
	while (at + cc <= tt) at += cc;
	
	if (tt < at + wt) return 0;
	return ((cc - wt) - (tt - (at + wt)));
}

#define PX pair < pair < LL, int >, PII >
int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		int n, m;
		cin >> n >> m;
		REP(i, n) REP(j, m) cin >> s[i][j] >> w[i][j] >> t[i][j];
		memset(dp, 0x3f, sizeof dp);
		priority_queue < PX, VC < PX >, greater < PX > > pq;
		pq.push(MP(MP(0, 2), MP(n - 1, 0)));
		printf("Case #%d: ", atc);
		while (!pq.empty()) {
		
			PX p = pq.top(); pq.pop();
			//cout << p.X.X << ' ' << p.X.Y << ' ' << p.Y.X << ' ' << p.Y.Y << endl;
			if (dp[p.Y.X][p.Y.Y][p.X.Y] <= p.X.X) continue;
			dp[p.Y.X][p.Y.Y][p.X.Y] = p.X.X;
			
			if (p.Y.X == 0 && p.Y.Y == m - 1 && p.X.Y == 1) {
				cout << p.X.X;
				break;
			}
			
			if ((p.X.Y & 2) == 0 && p.Y.X > 0)
				pq.push(MP(MP(p.X.X + 2, p.X.Y ^ 2), MP(p.Y.X - 1, p.Y.Y)));
			if ((p.X.Y & 2) != 0 && p.Y.X < n - 1)
				pq.push(MP(MP(p.X.X + 2, p.X.Y ^ 2), MP(p.Y.X + 1, p.Y.Y)));
			if ((p.X.Y & 1) == 0 && p.Y.Y > 0)
				pq.push(MP(MP(p.X.X + 2, p.X.Y ^ 1), MP(p.Y.X, p.Y.Y - 1)));
			if ((p.X.Y & 1) != 0 && p.Y.Y < m - 1)
				pq.push(MP(MP(p.X.X + 2, p.X.Y ^ 1), MP(p.Y.X, p.Y.Y + 1)));
				
			pq.push(MP(MP(p.X.X + 1 + waittime(p.Y, p.X.X, 0), p.X.Y ^ 2), p.Y));
			pq.push(MP(MP(p.X.X + 1 + waittime(p.Y, p.X.X, 1), p.X.Y ^ 1), p.Y));			
		}
		printf("\n");
	}
}
