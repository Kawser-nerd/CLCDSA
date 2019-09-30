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

LL a[37];
LL t[37];
LL x[37];

LL z;

void add(int p, LL v) {
	x[p] += v;
	t[p] += v;
	z -= v;
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		int n;
		LL b;
		cin >> b;
		cin >> n;
		ZERO(a);
		REP(i, n) cin >> a[i];
		sort(a, a + 37);
		
		double rv = 0;
		
		FOR(i, 1, 37) {
			if (a[i-1] == a[i]) continue;
			// DB(i);	
			FOR(j, 1, i+1) {
				ZERO(x);
				REP(k, 37) t[k] = a[k];
				z = b;
				REP(k, i) add(k, a[i-1]-a[k]);
				FOR(k, j, i) add(k, 1);
				if (z < 0) continue;
				LL mx = min(z / i, a[i]-a[i-1]-1);
				REP(k, i) add(k, mx);
				
				double av = 0;
				// print(VI(t, t + 37));
				// print(VI(x, x + 37));
				REP(k, j) av += x[k] * 36.0 / j;
				// DB(av);
				REP(k, 37) av -= x[k];
				// DB(av);
				rv = max(av, rv);
			}
		}
		
		printf("Case #%d: %.9f\n", atc, rv);
	}
}