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

#define MAXN 57
int C,N,K,B,T,X[MAXN],V[MAXN];
bool ok[MAXN];

int main(){
	cin >> C;
	FOR(cas,1,C){
        //in
        cin >> N >> K >> B >> T;
        REP(i,N) cin >> X[i];
        REP(i,N) cin >> V[i];
        //sol
        REP(i,N) ok[i] = (X[i] + V[i] * T >= B);
        int res = 0, bad = 0;
        FORD(i,N-1,0){
            if(!K) break;
            if(ok[i]){
                K--;
                res += bad;
            } else bad++;
        }
        //out
		cout << "Case #" << cas << ": ";
        if(K) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
	}
	return 0;
}
