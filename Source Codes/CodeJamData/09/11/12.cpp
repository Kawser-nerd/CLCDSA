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

#define MAX 1000000
#define MAXX 100000000
char mm[11][MAX];
int ishappy(int a, int b, int lv = 0) {
	if (a == 1) return 1;
	if (a < MAX && mm[b][a]) return mm[b][a] == 1;
	if (lv > 1000) return 0;
	int x = 0;
	while (a > 0) {
		int z = a % b;
		x += z * z;
		a /= b;
	}
	return ishappy(x, b, lv + 1);
}

int main() {
	ZERO(mm);
	FOR(i, 2, 11) FOR(j, 1, MAX) {
		//cout << i << ' ' << j << endl;
		mm[i][j] = ishappy(j, i) ? 1 : -1;
	}
	int tc;
	cin >> tc;
	string s;
	getline(cin, s);
	map<VI, int> mp;
	FOR(atc,1,tc+1) {
		getline(cin, s);
		VS vs = splt(s);
		VI v;
		REP(i, vs.S) v.PB(atoi(vs[i].c_str()));
		sort(ALL(v));
		if (mp.count(v) == 0) {
			FOR(i, 2, MAXX) {
				REP(j, v.S) if (ishappy(i, v[j]) == 0) goto nxt;
				mp[v] = i;
				break;
				nxt: ;
			}
		}
		printf("Case #%d: %d", atc, mp[v]);
		printf("\n");
	}
}
