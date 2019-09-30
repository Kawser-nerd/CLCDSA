#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const int kN = 202 + 5;
int A, B, d[kN][kN];
std::vector<std::tuple<int, int, int>> edges;
int n = 202;
int S = 1, T = 202;

std::vector<std::pair<int, int>> graph[kN];

bool validate()
{
    for (int x = 1; x <= A; ++ x) {
        for (int y = 1; y <= B; ++ y) {
            for (int i = 1; i <= n; ++ i) graph[i].clear();
            for (auto t : edges) {
                int a, b, c;
                std::tie(a, b, c) = t;
                graph[a].emplace_back(b, c == -1 ? x : c == -2 ? y : c);
            }
            std::vector<int> dist(n + 1, 101);
            dist[S] = 0;
            std::priority_queue<std::pair<int, int>> pq;
            pq.emplace(0, S);
            while (!pq.empty()) {
                int u, tmp;
                std::tie(tmp, u) = pq.top(); pq.pop();
                if (-tmp != dist[u]) continue;
                for (auto t : graph[u]) {
                    int v, w;
                    std::tie(v, w) = t;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.emplace(-dist[v], v);
                    }
                }
            }
            if (dist[T] != d[x][y]) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d%d", &A, &B);
    for (int i = 1; i <= A; ++ i)
        for (int j = 1; j <= B; ++ j)
            scanf("%d", &d[i][j]);

    for (int i = 1; i < 101; ++ i)
        edges.emplace_back(i, i + 1, -1);
    for (int i = 102; i < 202; ++ i)
        edges.emplace_back(i, i + 1, -2);

    for (int i = 0; i <= 100; ++ i) {
        for (int j = 0; j <= 100; ++ j) {
            int v = 0;
            for (int x = 1; x <= A; ++ x)
                for (int y = 1; y <= B; ++ y)
                    v = std::max(v, d[x][y] - i * x - j * y);
            edges.emplace_back(i + 1, T - j, v);
        }
    }
    if (!validate())
        return puts("Impossible"), 0;
    puts("Possible");
    printf("%d %d\n", n, edges.size());
    for (auto t : edges) {
        int a, b, c;
        std::tie(a, b, c) = t;
        printf("%d %d ", a, b);
        if (c < 0) putchar("YX"[c + 2]);
        else printf("%d", c);
        puts("");
    }
    printf("%d %d\n", S, T);
} ./Main.cpp:72:26: warning: format specifies type 'int' but the argument has type 'size_type' (aka 'unsigned long') [-Wformat]
    printf("%d %d\n", n, edges.size());
               ~~        ^~~~~~~~~~~~
               %lu
1 warning generated.