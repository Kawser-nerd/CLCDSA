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

#define ALL(v) (v).begin(), (v).end()
#define REP(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define RESET(a,c) memset(a,(c),sizeof(a))
#define SORT(x) sort( (x).begin(), (x).end() ) 
#define PV(v) ({ cout << #v << " = "; for(int __i = 0; __i < (int)(v).size();++__i ) cout << (v)[__i] << " "; putchar('\n'); putchar('\n'); })


typedef long long LL;
/*PREWRITTEN CODE ENDS HERE*/
inline int RI() { int xx; scanf("%d",&xx); return xx; }
typedef long double LD;
const int INF = 1010000000;
const double EPS = 1e-9;
/*SOLUTION BEGINS HERE*/

const int MAX = 2*1000*1000 + 1000;
int nxt[MAX];
void solve()
{
	int L, N, C;
	LL t;
	scanf("%d %lld %d %d", &L, &t, &N, &C);
	
	RESET(nxt, -1);
	REP(i, C) {
		int a;
		scanf("%d", &a);
		REP(k, N) {
			if(k * C + i + 1 > N) break;
			assert(nxt[k*C + i] == -1);
			nxt[k*C + i] = a;
		}
	}
	REP(i, N) assert(nxt[i] != -1);
	
	//REP(i, N) printf("nxt[%d]: %d\n", i, nxt[i]);
	REP(i, N) nxt[i] *= 2;
	//t *= 2;
	
	LL sum = 0;
	vector<LL> vec;
	REP(i, N) {
		if(sum >= t) vec.PB(nxt[i]);
		else if(sum + nxt[i] >= t) { 
			vec.PB(sum + nxt[i] - t); 
			sum += (t-sum);
		}
		else sum += nxt[i];
	}
	SORT(vec);
	reverse(ALL(vec));
 	
	//PV(vec);
	REP(i, min(L, SIZE(vec))) 
		sum += vec[i]/2;
	
	FOR(i, min(L, SIZE(vec)), SIZE(vec)-1) 
		sum += vec[i];
	printf("%lld\n", sum);
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
