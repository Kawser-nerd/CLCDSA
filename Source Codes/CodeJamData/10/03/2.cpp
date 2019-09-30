#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>
#define MAX(a,b) ((a)>(b))?((a):(b))
#define MIN(a,b) ((a)<(b))?((a):(b))

int R, k, N;

ll val[2 * 1011];
ll dp[1011][30];
int np[1011][30];

void solve() {
    scanf("%d%d%d", &R, &k, &N);
    rep (i, N) scanf("%lld", &val[i]);
    rep (i, N) val[N+i] = val[i];

    rep (i, N) {
        int cp = i;
        ll cur = 0;
        while (cp < N + i && cur + val[cp] <= k) {
            cur += val[cp];
            cp++;
        }
        dp[i][0] = cur;
        np[i][0] = cp % N;
    }
    fo (di, 1, 29) {
        rep (i, N) {
            ll v1 = dp[i][di-1];
            int sr = np[i][di-1];
            ll v2 = dp[sr][di-1];
            int kon = np[sr][di-1];

            dp[i][di] = v1 + v2;
            np[i][di] = kon;
        }
    }
    ll result = 0;
    int cp = 0;
    for (int i = 29; i >= 0; i--) if (R&(1<<i)) {
        result += dp[cp][i];
        cp = np[cp][i];
    }

    printf(" %lld", result);
}

int main(int argc, char ** argv) {
   int t;
   scanf("%d", &t);
   rep (i, t) {
       printf("Case #%d:", i+1);
       solve();
       printf("\n");
   }
   return 0;
}



