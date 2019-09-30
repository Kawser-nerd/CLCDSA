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

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

int n;

double dp[1<<20];

double go(int x) {
	double &rv = dp[x];
	if (rv >= -0.5) return rv;
	
	if (x == (1<<n)-1) return rv = 0;
	
	rv = 0;
	REP(i, n) {
		REP(j, n) if ((x & (1 << ((i+j)%n))) == 0) {
			rv += n - j;
			rv += go(x | (1 << ((i+j)%n)));
			break;
		}
	}
	return rv /= n;
}
int main() {
	int tc;
	cin >> tc;
	FOR(atc,1,tc+1) {
		string s;
		cin >> s;
		n = s.S;
		int x = 0;
		REP(i, 1<<n) dp[i] = -1;
		REP(i, s.S) if (s[i] == 'X') x += 1 << i;
		printf("Case #%d: %.9f\n", atc, go(x));
	}
	return 0;
}