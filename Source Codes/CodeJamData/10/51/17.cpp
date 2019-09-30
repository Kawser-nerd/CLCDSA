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

typedef lli TYP;

TYP NWD(TYP a,TYP b){
    if(b == 0) return a;
    return NWD(b,a%b);
}
typedef pair<TYP, TYP> TT;
TT Euk(TYP a,TYP b){
    if(b == 0) return TT(1,0);
    TT tt=Euk(b,a%b);
    return TT(tt.yy,tt.xx-(a/b)*tt.yy);
}

lli norm(lli x,lli p){x%=p; if(x<0) x+=p; return x;}
lli odwr(lli x,lli p){return norm(Euk(x,p).xx,p);}

#define MAXN 1000007
lli T,D,K,x[17];
bool prime[MAXN];

lli solve(lli P){
//    cout << P << endl;
    REP(i,K) if(x[i] >= P) return -1;
    if(K == 1) return -2;
    if(K == 2){
        if(x[1] == x[0]) return x[0];
        else return -2;
    }
    if(x[0] == x[1]){
        REP(i,K) if(x[i] != x[0]) return -1;
        return x[0];
    }
    lli A = ((x[1]-x[2]) * odwr(norm(x[0] - x[1], P) , P)) % P;
    A = norm(A, P);
    lli B = x[1] - A * x[0];
    B = norm(B, P);
    REP(i,K-1) if((x[i]*A+B)%P != x[i+1]) return -1;
    return (x[K-1]*A+B)%P;
}

int main(){
    FOR(i,2,MAXN-1) prime[i] = true;
    FOR(i,2,MAXN-1){
        for(lli j = ((lli)i)*i; j < MAXN; j += i)
            prime[j] = false;
    }
	cin >> T;
	FOR(cas,1,T){
        //in
        cin >> D >> K;
        REP(i,K) cin >> x[i];
        //rozw
        lli res = -1, ogr = 1;
        REP(i,D) ogr *= 10;
        REP(i,ogr+1) if(prime[i]){
            lli x = solve(i);
            if(x == -2) res = -2;
            else if(x != -1){
                if(res == -1 || res == x) res = x;
                else res = -2;
            }
        }
        //out
		cout << "Case #" << cas << ": ";
        if(res == -1) cout << "ERROR" << endl;
        if(res == -2) cout << "I don't know." << endl;
        else cout << res << endl;
	}
	return 0;
}
