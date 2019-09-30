#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
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

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

#define CORRECT "Looks Good To Me"

int n, m, p;
VI cn[2100];
VI ca[2100];
VI cb[2100];
int order[2100];
int cc[2100];
int cv[2100];

LL mx[2100];
LL mx2[2100];
LL mn[2100];

int vs[2100];

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		cin >> n >> m >> p;
		REP(i, n) cn[i].clear(), ca[i].clear(), cb[i].clear();
		REP(i, m) {
			int u, v, a, b;
			cin >> u >> v >> a >> b;
			u--;
			v--;
			cn[u].PB(v);
			ca[u].PB(a);
			cb[u].PB(b);
			cc[i] = v;
			cv[i] = a;
		}
	
		printf("Case #%d: ", atc);
		REP(i, p) cin >> order[i];
		REP(i, p) order[i]--;
		
		
		#define PX pair < LL, LL > 
		
		{
			priority_queue < PX, VC < PX >, greater < PX > > pq;
			
			memset(mx2, 0x3F, sizeof(mx));
			pq.push(MP(0, 0));
			while (!pq.empty()) {
				PII p = pq.top(); pq.pop();
				if (p.X >= mx2[p.Y]) continue;
				mx2[p.Y] = p.X;
				REP(i, cn[p.Y].S) pq.push(MP(p.X + cb[p.Y][i], cn[p.Y][i]));
			}
		}
		
		
		int curCity = 0;
		LL curCost = 0;
		ZERO(vs);
		
		vs[0] = 1;
		REP(i, p) {
		
			priority_queue < PX, VC < PX >, greater < PX > > pq;
			
			pq.push(MP(curCost, curCity));
			while (!pq.empty()) {
				PII p = pq.top(); pq.pop();
				if (p.X >= mx2[p.Y]) continue;
				mx2[p.Y] = p.X;
				REP(i, cn[p.Y].S) pq.push(MP(p.X + cb[p.Y][i], cn[p.Y][i]));
			}
			
			
			
			
			priority_queue < PX, VC < PX >, greater < PX > > pp;
			memset(mn, 0x3F, sizeof(mx));
			pp.push(MP(cv[order[i]]+curCost, cc[order[i]]));
			while (!pp.empty()) {
				PII p = pp.top(); pp.pop();
				if (p.X > mx2[p.Y]) continue;
				if (p.X >= mn[p.Y]) continue;
				mn[p.Y] = p.X;
				REP(i, cn[p.Y].S) pp.push(MP(p.X + ca[p.Y][i], cn[p.Y][i]));
			}
			
			// DB(order[i]);
			// DB(cv[order[i]]);
			// DB(curCity);
			// DB(mn[1]);
			// DB(mx[1]);
			if (mn[1] > mx2[1] || vs[cc[order[i]]]) {
				cout << (order[i]+1);
				goto next;
			}
			curCity = cc[order[i]];
			curCost += cv[order[i]];
			vs[curCity] = 1;
			
		}
		
		cout << CORRECT;
		next: ;
		cout << endl;
	}
	return 0;
}