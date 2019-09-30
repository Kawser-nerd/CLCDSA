#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

#define EQ(a,b) (abs((a)-(b)) < 1e-7)

int A,V,M; 
double dp[22];

double acc(int n) {
    if (n<=0) return 0.0;
    if (n>=V) return 1.0;
    return dp[n];
}

double sub(int n, int b) {
    int phase=0;
    assert(b <= M);
    for (; b*(1<<(phase+1)) <= M; phase++);

    double mm=0;
    for (; phase>=0; phase--) {
        assert(b*(1<<phase) <= M);
        mm=0.5*acc(n+b) + 0.5*max(acc(n-b*((1<<(phase+1))-1)), mm);
    }
    //cout<<"#"<<mm<<endl;
    return mm;
}

void solve() {
    scanf("%d%d%d", &A, &M, &V);
    REP(i, V) dp[i] = 0.0;

        // ???
    for (int itr=0; itr<9999; ++itr) {
        REP(n, V) {
            double good=0.0;
            FOREQ(b, 1, min(n, M)) {
                good = max(good, sub(n, b));
            }
            dp[n] = good;
        }
    }

    int nice=666;
    FOREQ(b, 1, min(A, M)) {
        if (EQ(dp[A], sub(A, b))) nice=b;
    }

    printf("%.9f %d\n", dp[A], nice);
}

int main() {
    int total; scanf("%d", &total);
    for (int test=1; test<=total; test++) {
        printf("Case #%d: ", test);
        solve();
    }
}
