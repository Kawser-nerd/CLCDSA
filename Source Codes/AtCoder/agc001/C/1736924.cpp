#include <algorithm>
#include <cstdio>
#include <vector>

const int N = 2000;

int n, m;
std::vector<int> tree[N];

int dfs(int p, int u, int d)
{
    if (d == 0) {
        return 1;
    }
    int result = 1;
    for (auto v : tree[u]) {
        if (v != p) {
            result += dfs(u, v, d - 1);
        }
    }
    return result;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int result = 0;
    for (int u = 0; u < n; ++ u) {
        result = std::max(result, dfs(-1, u, m >> 1));
        for (auto v : tree[u]) {
            result = std::max(result, dfs(u, v, m - 1 >> 1) + dfs(v, u, m - 1 >> 1));
        }
    }
    printf("%d\n", n - result);
} ./Main.cpp:39:51: warning: operator '>>' has lower precedence than '-'; '-' will be evaluated first [-Wshift-op-parentheses]
            result = std::max(result, dfs(u, v, m - 1 >> 1) + dfs(v, u, m - 1 >> 1));
                                                ~~^~~ ~~
./Main.cpp:39:51: note: place parentheses around the '-' expression to silence this warning
            result = std::max(result, dfs(u, v, m - 1 >> 1) + dfs(v, u, m - 1 >> 1));
                                                  ^
                                                (    )
./Main.cpp:39:75: warning: operator '>>' has lower precedence than '-'; '-' will be evaluated first [-Wshift-op-parentheses]
            result = std::max(result, dfs(u, v, m - 1 >> 1) + dfs(v, u, m - 1 >> 1));
                                                                        ~~^~~ ~~
./Main.cpp:39:75: note: place parentheses around the '-' expression to silence this warning
            result = std::max(result, dfs(u, v, m - 1 >> 1) + dfs(v, u, m - 1 >> 1));
 ...