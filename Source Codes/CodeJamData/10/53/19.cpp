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
typedef vector<int> vi;

int T,C,P,V;
lli res;
map<int, int> ile;

void go(int x){
    if(ile[x]<2) return;
    int r = ile[x]/2;
    res += r;
    ile[x] -= 2*r;
    ile[x-1] += r;
    ile[x+1] += r;
    go(x-1);
    go(x+1);
}

int main(){
	cin >> T;
	FOR(cas,1,T){
        //in
        ile.clear();
        res = 0;
        cin >> C;
        while(C--){
            cin >> P >> V;
            ile[P] = V;
        }
        //rozw
        map<int, int> M = ile;
        FORE(i,M) go(i->xx);
        //out
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
