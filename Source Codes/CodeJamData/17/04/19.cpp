#include <bits/stdc++.h>
using namespace std;

char dat[111][111];
bool row[111], col[111];
bool xpy[222], xmy[222];
bool changed[111][111];

// in: n, m, graph
// out: match, matched
// vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
// O(E*sqrt(V))
struct BipartiteMatching {
    int n, m;
    vector<vector<int>> graph;
    vector<int> matched, match, edgeview, level;
    vector<int> reached[2];
    BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1),
    match(n, -1) {}
    bool assignLevel() {
        bool reachable = false;
        level.assign(n, -1);
        reached[0].assign(n, 0);
        reached[1].assign(m, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (match[i] == -1) {
                level[i] = 0;
                reached[0][i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto adj : graph[cur]) {
                reached[1][adj] = 1;
                auto next = matched[adj];
                if (next == -1) {
                    reachable = true;
                }
                else if (level[next] == -1) {
                    level[next] = level[cur] + 1;
                    reached[0][next] = 1;
                    q.push(next);
                }
            }
        }
        return reachable;
    }
    int findpath(int nod) {
        for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
            int adj = graph[nod][i];
            int next = matched[adj];
            if (next >= 0 && level[next] != level[nod] + 1) continue;
            if (next == -1 || findpath(next)) {
                match[nod] = adj;
                matched[adj] = nod;
                return 1;
            }
        }
        return 0;
    }
    int solve() {
        int ans = 0;
        while (assignLevel()) {
            edgeview.assign(n, 0);
            for (int i = 0; i < n; i++)
                if (match[i] == -1)
                    ans += findpath(i);
        }
        return ans;
    }
};

char calc(int t)
{
    if (t == 1) return '+';
    if (t == 2) return 'x';
    if (t == 3) return 'o';
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        memset(dat, 0, sizeof(dat));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(xpy, 0, sizeof(xpy));
        memset(xmy, 0, sizeof(xmy));
        memset(changed, 0, sizeof(changed));

        int n, m;
        scanf("%d%d",&n,&m);

        int score = 0;
        for (int i = 0; i < m; i++)
        {
            char ch; int x, y;
            scanf(" %c%d%d",&ch,&x,&y);
            x--; y--;
            if (ch == '+') ch = 1;
            else if (ch == 'x') ch = 2;
            else ch = 3;
            dat[x][y] = ch;
            if (ch & 2)
            {
                row[x] = true;
                col[y] = true;
            }

            if (ch & 1)
            {
                xpy[x + y] = true;
                xmy[x - y + 100] = true;
            }

            if (ch == 3) score += 2;
            else score += 1;
        }

        BipartiteMatching bm1(n, n);

        for (int i = 0; i < n; i++)
        {
            if (row[i]) continue;
            for (int j = 0; j < n; j++)
            {
                if (col[j]) continue;
                bm1.graph[i].push_back(j);
            }
        }

        score += bm1.solve();

        for (int i = 0; i < n; i++)
        {
            if (bm1.match[i] == -1) continue;
            dat[i][bm1.match[i]] |= 2;
            changed[i][bm1.match[i]] = true;
        }

        BipartiteMatching bm2(220, 220);

        for (int i = 0; i < 220; i++)
        {
            if (xpy[i]) continue;
            for (int j = 0; j < 220; j++)
            {
                if ((i + j) & 1) continue;
                if (xmy[j]) continue;

                int x = (i + j - 100) / 2;
                int y = (i - j + 100) / 2;
                if (x < 0 || x >= n || y < 0 || y >= n) continue;

                bm2.graph[i].push_back(j);
            }
        }

        score += bm2.solve();
        for (int i = 0; i < 220; i++)
        {
            if (bm2.match[i] == -1) continue;
            int j = bm2.match[i];

            int x = (i + j - 100) / 2;
            int y = (i - j + 100) / 2;

            dat[x][y] |= 1;
            changed[x][y] = true;
        }

        vector<pair<int, int>> vt;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (changed[i][j]) vt.emplace_back(i, j);
            }
        }

        printf("Case #%d: %d %zd\n", tt, score, vt.size());
        for (auto e : vt)
        {
            printf("%c %d %d\n", calc(dat[e.first][e.second]), e.first + 1, e.second + 1);
        }
    }
}
