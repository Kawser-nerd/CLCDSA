#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define FORE(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define debug(x) cerr << #x << " = " << x << "\n";
#define debugv(x) cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n";
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof x)
#define xx first
#define yy second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> vi;

#define MOD 1000000007LL
#define MAXN 107
lli T,N,B,dp[MAXN][13];

int main(){
	cin >> T;
	FOR(cas,1,T){
        //in
        cin >> N >> B;
        //rozw
        CLR(dp);
        dp[0][0] = 1;
        FOR(s,1,N) REP(q, (1 << B)){
            lli suma = 0, ile = 0;
            REP(j,B) if(q&(1 << j)) {suma += j; ile++;}
            if(suma%B != s%B) continue;
            lli ss = (s - suma) / B;
            if(ss < 0) continue;
            REP(pop,ile+1){
                lli wsp = 1, wsp2 = 0;
                REP(i,pop) {wsp *= (ile-i); wsp%=MOD;}
                if(q&1){
                    wsp2 = 1;
                    REP(i,pop) {wsp2 *= (ile-1-i); wsp2%=MOD;}
                }
                wsp = (wsp - wsp2 + MOD)%MOD;
                dp[s][ile] += wsp * dp[ss][pop];
                dp[s][ile] %= MOD;
            }
        }
//        REP(i,N+1) REP(j,B+1) if(dp[i][j]) cout << i << " " << j << " = "  << dp[i][j] << endl;
        lli res = 0;
        REP(i,B+1){res+=dp[N][i]; res%=MOD;}
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
