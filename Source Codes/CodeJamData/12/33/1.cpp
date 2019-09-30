#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <tr1/unordered_map>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

const int N = 105;

LL dp[N][N];

struct Element {
    int type;
    LL count;
};

Element a[N];
Element b[N];

int n, m;

void alg() {
    ZERO(dp);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %d", &a[i].count, &a[i].type);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%lld %d", &b[i].count, &b[i].type);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i].type == b[j].type) {
                LL totalA = a[i].count;
                LL totalB = b[j].count;
                int prevA = i - 1;
                int prevB = j - 1;
                while (true) {
                    dp[i][j] = max(dp[i][j], dp[prevA][prevB] + min(totalA, totalB));
                    int state = (totalA < totalB) ? -1 : (totalA == totalB ? 0 : 1);
                    bool finished = false;
                    if (state <= 0) {
                        while (prevA > 0 && a[prevA].type != a[i].type) {
                            --prevA;
                        }
                        if (prevA == 0) {
                            finished = true;
                        } else {
                            totalA += a[prevA].count;
                            --prevA;
                        }
                    }
                    if (state >= 0) {
                        while (prevB > 0 && b[prevB].type != b[j].type) {
                            --prevB;
                        }
                        if (prevB == 0) {
                            finished = true;
                        } else {
                            totalB += b[prevB].count;
                            --prevB;
                        }
                    }
                    if (finished) {
                        break;
                    }
                }
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    static int case_no = 0;
    printf("Case #%d: %lld\n", ++case_no, dp[n][m]);
}

int main() {
    int d;
    scanf("%d", &d);
    while (d--) {
        alg();
    }
}
