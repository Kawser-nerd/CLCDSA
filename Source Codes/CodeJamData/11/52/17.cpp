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

void solve() {
    int m; scanf("%d", &m);
    if (m==0) { // edge case
        puts("0");
        return;
    }
    int vi[m];
    REP(i, m) scanf("%d", vi+i);
        // greedy~~~~
    int N=10010;
    int nums[N+10]; MEMSET(nums, 0);
    REP(i, m) nums[vi[i]]++;

    int res = 1<<20;
    vector<int> len;
    FOREQ(j, 0, N) {
        sort(len.begin(), len.end());
        if (nums[j] <= SZ(len)) {
            int u = SZ(len)-nums[j];
            //if (u) cout<<"#"<<j<<" "<<u<<endl;
            REP(i, u) { res = min(res, len.back()); len.pop_back(); }
        }
        else {
            int u = nums[j]-SZ(len);
            REP(i, u) len.push_back(0);
        }
        REP(i, SZ(len)) len[i]++;
    }
    printf("%d\n", res);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        static int test = 1;
        printf("Case #%d: ",test++);
        solve();
    }
}
