#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 16;

int R, C;
int a[MAXN + MAXN], b[MAXN + MAXN];
vector<int> adj[(MAXN + MAXN) * 2 + MAXN * MAXN * 2];
int color[(MAXN + MAXN) * 2 + MAXN * MAXN * 2];

void flood(int u, int c)
{
    color[u] = c;
    for (int i = 0; i < adj[u].size(); ++ i) {
        int v = adj[u][i];
        if (color[v] == -1) {
            flood(v, c);
        }
    }
}

void addEdge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void addEdge(int i, int j, int k, int x)
{
    addEdge((R + C) * 2 + (i * C + j) * 2 + k, x);
}

void addEdge(int i, int j, int k, int a, int b, int c)
{
    addEdge((R + C) * 2 + (i * C + j) * 2 + k, (R + C) * 2 + (a * C + b) * 2 + c);
}

int getType(int mask, int i, int j)
{
    return mask >> (i * C + j) & 1;
}

void solve()
{
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R + C; ++ i) {
        scanf("%d%d", &a[i], &b[i]);
        -- a[i];
        -- b[i];
    }

    for (int mask = 0; mask < 1 << R * C; ++ mask) {
        // construct graph
        for (int i = 0; i < (R + C) * 2 + R * C * 2; ++ i) {
            adj[i].clear();
        }
        for (int i = 0; i < R; ++ i) {
            for (int j = 0; j < C; ++ j) {
                int current = getType(mask, i, j);

                if (i == 0) {
                    addEdge(i, j, 0, j);
                }
                if (j == C - 1) {
                    addEdge(i, j, current == 0 ? 1 : 0, C + i);
                }
                if (i == R - 1) {
                    addEdge(i, j, 1, C + R + (C - 1 - j));
                }
                if (j == 0) {
                    addEdge(i, j, current == 0 ? 0 : 1, C + R + C + (R - 1 - i));
                }

                if (i + 1 < R) {
                    int down = getType(mask, i + 1, j);
                    if (current == 0 && down == 0) {
                        addEdge(i, j, 1, i + 1, j, 0);
                    }
                    if (current == 0 && down == 1) {
                        addEdge(i, j, 1, i + 1, j, 0);
                    }
                    if (current == 1 && down == 0) {
                        addEdge(i, j, 1, i + 1, j, 0);
                    }
                    if (current == 1 && down == 1) {
                        addEdge(i, j, 1, i + 1, j, 0);
                    }
                }
                if (j + 1 < C) {
                    int right = getType(mask, i, j + 1);
                    if (current == 0 && right == 0) {
                        addEdge(i, j, 1, i, j + 1, 0);
                    }
                    if (current == 0 && right == 1) {
                        addEdge(i, j, 1, i, j + 1, 1);
                    }
                    if (current == 1 && right == 0) {
                        addEdge(i, j, 0, i, j + 1, 0);
                    }
                    if (current == 1 && right == 1) {
                        addEdge(i, j, 0, i, j + 1, 1);
                    }
                }
            }
        }

        memset(color, -1, sizeof(color));
        for (int i = 0; i < (R + C) * 2; ++ i) {
            if (color[i] == -1) {
                flood(i, i);
            }
        }
        bool valid = true;
        for (int i = 0; i < R + C; ++ i) {
            if (color[a[i]] != color[b[i]]) {
                valid = false;
            }
        }

        if (valid) {
            for (int i = 0; i < R; ++ i) {
                for (int j = 0; j < C; ++ j) {
                    int current = getType(mask, i, j);
                    if (current == 0) {
                        printf("/");
                    } else {
                        printf("\\");
                    }
                }
                puts("");
            }
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}

int main()
{
    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        printf("Case #%d:\n", test);
        solve();
    }
    return 0;
}
