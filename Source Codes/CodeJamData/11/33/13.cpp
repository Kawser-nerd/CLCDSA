#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
using namespace std;

/*PREWRITTEN CODE BEGINS HERE*/
#define PB push_back
#define SIZE(x) (int)((x).size())

#define REP(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define SORT(x) sort( (x).begin(), (x).end() ) 
#define DB(x) cout << #x << "=" << x << endl 
#define PV(v) ({ cout << #v << " = "; for(int __i = 0; __i < (int)(v).size();++__i ) cout << (v)[__i] << " "; putchar('\n'); putchar('\n'); })


typedef long long LL;
template<typename MyType>
MyType gcd(const MyType &a, const MyType &b) {
	if( b == 0) return a;
	return gcd( b, a % b);
}
template<typename MyType>
MyType lcm(const MyType &a, const MyType &b) {
	return (a / gcd(a,b)) * b;
}
/*PREWRITTEN CODE ENDS HERE*/
inline int RI() { int xx; scanf("%d",&xx); return xx; }
typedef long double LD;
const int INF = 1010000000;
const double EPS = 1e-9;
/*SOLUTION BEGINS HERE*/

LL gcd(LL a, LL b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

LL try_all_divs(LL x, vector<LL> &freq, LL L, LL H)
{
	vector<LL> divs;

	for(LL i = 1; i * i <= x; i++) if(x % i == 0) {
		if(i >= L && i <= H) divs.PB(i);
		if(x/i >= L && x/i <= H) divs.PB(x/i);
	}
	
	SORT(divs);
	REP(i, SIZE(divs)) {
		bool ok = true;
		REP(j, SIZE(freq))
			if(freq[j] % divs[i] != 0) {ok = false; break; }

//		if(ok) DB(divs[i]);
		if(ok) return divs[i];
	}
		

	return -1;
}

const long long OVERF = 1000LL*1000LL*1000LL*1000LL*1000LL*100LL;

//min c takie ze  L <= c * lcm <= H  i   c | gcd_c
LL find_bst_c(LL lcm, LL gcd_c, LL L, LL H) 
{
	
	vector<LL> divs;

	for(LL i = 1; i * i <= gcd_c; i++) if(gcd_c % i == 0) {
		divs.PB(i);
		divs.PB(gcd_c/i);
	}
	
	SORT(divs);
	REP(i, SIZE(divs)) {
		LL c = divs[i];
		if(lcm * c >= L && lcm * c <= H) return c;
	}

	return -1;
}

void solve()
{
	int N;
	LL L, H;
	scanf("%d %lld %lld", &N, &L, &H);
	vector<LL> freq;
	REP(i, N) {
		LL f;
		scanf("%lld", &f);
		freq.PB(f);
	}
	SORT(freq);

	if(L == 1) { printf("1\n"); return ; }
	LL x = try_all_divs(freq[0], freq, L, H);
	if(x != -1) { printf("%lld\n", x); return ; }
	LL lcm = 1;
	REP(i, N) {
		LL g = gcd(lcm, freq[i]);
		freq[i] /= g;
		if(lcm >= OVERF/freq[i]) break;
		lcm *= freq[i];
		
		if(i == N-1) {
			LL c = L/lcm;
			REP(xx, 3) {
				if(c * lcm >= L && c * lcm <= H) {
					printf("%lld\n", c*lcm); return; 
				}
				c++;
			}
			continue;
		}

		
		bool ok = true;
		LL gcd_c = freq[i+1];
		FOR(j, i+1, N-1) {
			if(freq[j] % lcm != 0) { ok = false; break; }
			gcd_c = gcd(gcd_c, freq[j]/lcm);
		}
		if(!ok) continue;
		
		LL c = find_bst_c(lcm, gcd_c, L, H);
		if(c != -1) { printf("%lld\n", lcm * c); return ; }
	}

	printf("NO\n");
}

int main(void)
{
	int T = RI();
	FOR(i,1,T) {
		printf("Case #%d: ", i);
        solve();
	}
	return (0);
}
