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
#define FORIT(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

void solve_small() {
    string s; cin>>s;
    int N=SZ(s);
    int Q=0;
    REP(i, N) if (s[i] == '?') Q++;
    REP(itr, 1<<Q) {
        int u = 0;
        ll num = 0;
        REP(i, N) {
            if (s[N-1-i] == '?') {
                if ((itr>>u)&1) num|=1LL<<i;
                u++;
            }
            else if (s[N-1-i] == '1') num|=1LL<<i;
        }
        ll sqr=(ll)sqrt((double)num);
        for (ll u=sqr-10LL; u<=sqr+10LL; ++u) {
            if (u*u == num) {
                REP(i, N) printf("%lld", (num>>(N-1-i))&1LL);
                puts("");
                return;
            }
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve_small();
    }
}
