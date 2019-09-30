#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(int i = (a);i<=(b);++i)
#define FORD(i,a,b) for(int i = (a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int N;
#define SZ (10000 + 1)
int EXA[SZ];
int DA[SZ][3];

#define XX (1<<15)
int ILE[XX];


void add(int i, int val) {
    int p = XX / 2 + i + 1;
    while (p >= 1) {
        ILE[p] += val;
        p /= 2;
    }
}

int get(int i) {
    int p = XX /2 + i + 1;
    int ret = ILE[p];
    while (p > 1) {
        int other = p ^ 1;
        if (p < other) ret += ILE[other];
        p /= 2;
    }
    return ret;
}



int solve() {
    int ret = 0;
    CLR(EXA, 0);
    cin >> N;
    REP (i, N) REP (j, 3) cin >> DA[i][j];
    REP (i, N) EXA[DA[i][0]] = 1;
    FOR (a, 0, SZ - 1) if (EXA[a]) {
        CLR(ILE, 0);
        int sum = 10000 - a;
        REP (i, N) if (DA[i][0] <= a){ 
            // DATA[i][1] 
            int le = DA[i][1];
            int ri = sum - DA[i][2];
            if (le <= ri) {
                add(le - 1, -1);
                add(ri, 1);
            }
        }
        FOR (b, 0, sum) {
            ret = max(ret, get(b));
        }
    }   
    return ret;
}

int main(int argc, char ** argv) { ios::sync_with_stdio(false);
    COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
    int T; cin >> T;
    FOR (my, 1, T) {
        DB(my);
        printf("Case #%d: %d\n", my, solve());
    }

    return 0;
}
