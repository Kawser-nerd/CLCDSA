#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int MAXN = 222;
constexpr int INF = 5e8;
int n, m, r;
int order[MAXN];
ll dist[MAXN][MAXN];

int main() {
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < r; ++i) {
        scanf("%d", order + i);
        --order[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INF;
        }

        dist[i][i] = 0;
    }

    int u, v;
    ll w;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &u, &v, &w);
        --u; --v;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    sort(order, order + r);
    ll ans = 1e18;
    do {
        ll cur = 0LL;
        for (int i = 1; i < r; ++i) {
            cur = cur + dist[order[i - 1]][order[i]];
        }

        ans = min(ans, cur);
    } while (next_permutation(order, order + r));

    printf("%lld\n", ans);

    return 0;
}