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
#define X first
#define Y second
typedef long long int lli;
typedef pair<lli, lli> P;
typedef vector<int> vi;

lli nwd(lli a,lli b){
    if(!b) return a;
    return nwd(b,a%b);
}

#define MAXN 107
#define MAXB 100007
#define INF ((lli)((1E18)+7))
lli T,L,N,x;
vector<lli> a;
lli naj[MAXB];


int main(){
	cin >> T;
	FOR(cas,1,T){
        //in
        cin >> L >> N;
        a.clear();
        REP(i,N) {cin >> x; a.PB(x);}
        lli res = -1;
        //rozw
        sort(ALL(a));
        reverse(ALL(a));
        lli M = a[0];
            //dp
            REP(i,M) naj[i] = INF;
            priority_queue<P> Q;
            naj[0] = 0;
            Q.push(P(0,0));
            while(!Q.empty()){
                P p = Q.top(); Q.pop();
                lli k = -p.X, v = p.Y;
                if(v == L%M) break;
                FORE(i,a){
                    lli kk = k + 1 - ((v + *i) / M);
                    lli vv = (v + *i) % M;
                    if(naj[vv] > kk){
                        naj[vv] = kk;
                        Q.push(P(-kk, vv));
                    }
                }
            }
;
            res = (L/M) + naj[L%M];
		cout << "Case #" << cas << ": ";
        if(naj[L%M] == INF) cout << "IMPOSSIBLE" << endl;
        else cout << res << endl;
	}
	return 0;
}
