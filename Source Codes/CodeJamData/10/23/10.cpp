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

#define MOD 100003
#define MAXN 507

int T,N;
lli dp[MAXN][MAXN], dw[MAXN][MAXN];

int main(){
    REP(i,MAXN){
        dw[i][0] = 1;
        FOR(j,1,i) dw[i][j] = (dw[i-1][j-1] + dw[i-1][j]) % MOD;
    }
    //
    dp[1][0] = 1;
    FOR(n,2,MAXN-1)
        FOR(k,1,n-1)
            REP(i,k)
             dp[n][k] = (dp[n][k] + dp[k][i] * dw[n-k-1][k-i-1]) % MOD;
    //
	cin >> T;
	FOR(cas,1,T){
        cin >> N;
        int res = 0;
        REP(i,N+1) res = (res + dp[N][i]) % MOD;
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
