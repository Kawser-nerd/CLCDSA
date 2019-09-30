#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> triple;

const int MAXN = 128;
const int INF = 1000000007;

int x[MAXN], y[MAXN], z[MAXN];
int mind[MAXN][MAXN];

int main() {
    int re, n, ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        priority_queue<pair<pair<int, int>, int> > pq;
        scanf("%d", &n);
        fill(mind[0], mind[n + 1], INF);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            int t = max(max(abs(x[i]), abs(y[i])) * 100, z[i]);
            if (t <= z[i] + 1000) {
                mind[1][i] = t;
                pq.push({{1, i}, -mind[1][i]});
            }
        }

        ans = 0;
        while (!pq.empty()) {
            int m = pq.top().first.first;
            int p = pq.top().first.second;
            int d = -pq.top().second;
            pq.pop();
            if (mind[m][p] != d) {
                continue;
            }
            ans = max(ans, m);
            for (int i = 0; i < n; ++i) {
                if (i == p) {
                    continue;
                }
                int t = max(
                    d + max(750, max(abs(x[i] - x[p]), abs(y[i] - y[p])) * 100),
                    z[i]);
                if (t <= z[i] + 1000 && t < mind[m + 1][i]) {
                    mind[m + 1][i] = t;
                    pq.push({{m + 1, i}, -mind[m + 1][i]});
                }
            }
        }

        printf("Case #%d: %d\n", ri, ans);
    }

    return 0;
}


