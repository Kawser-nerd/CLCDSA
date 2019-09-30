#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define cmpby(_x) [](const auto& a, const auto& b) {return (a _x) < (b _x);}
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 105;

struct edge {
    int f, c;
    edge() {
        f = c = 0;
    }
    edge(int _c) {
        f = 0;
        c = _c;
    }
};

vector<edge> edges;
vector<vector<pii>> graph;

void add_edge(int a, int b, int c) {
    //cerr << a << " " << b << endl;
    graph[a].puba({b, szof(edges)});
    edges.puba(edge(c));
    graph[b].puba({a, szof(edges)});
    edges.puba(edge(0));
}

char field[MAXN][MAXN];
char inp[MAXN][MAXN];

int n, m;

int on_field(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

vector<int> dist;

int bfs(int s, int t) {
    dist.resize(szof(graph));
    fill(bend(dist), INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (szof(q)) {
        int v = q.front();
        q.pop();
        for (pii to : graph[v]) {
            if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] > dist[v] + 1) {
                dist[to.ff] = dist[v] + 1;
                q.push(to.ff);
            }
        }
    }
    return dist[t] < INF;
}

vector<int> cnt;

int dfs(int v, int t, int flow) {
    //cerr << v << " " << t << " " << flow << endl;
    if (v == t) {
        return flow;
    }
    for (; cnt[v] < szof(graph[v]); ++cnt[v]) {
        auto& to = graph[v][cnt[v]];
        if (edges[to.ss].f < edges[to.ss].c && dist[to.ff] == dist[v] + 1) {
            int tmp = dfs(to.ff, t, min(flow, edges[to.ss].c - edges[to.ss].f));
            if (tmp) {
                edges[to.ss].f += tmp;
                edges[to.ss ^ 1].f -= tmp;
                return tmp;
            }
        }
    }
    return 0;
}

int solve() {
    edges.clear();
    graph.clear();

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inp[i][j] = field[i][j] = '.';
        }
    }
    
    for (int i = 0; i < m; ++i) {
        char c;
        int x, y;
        scanf("\n%c%d%d", &c, &x, &y);
        --x; --y;
        field[x][y] = c;
        inp[x][y] = c;
    }
    
    int s = 0, t = 1;
    graph.resize(2);

    int from1 = szof(graph);
    graph.resize(szof(graph) + n * n);

    for (int i = 0; i < n; ++i) {
        graph.puba(vector<pii>());
        add_edge(s, szof(graph) - 1, 1);
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 'x' || field[i][j] == 'o') {
                flag = false;
                add_edge(szof(graph) - 1, from1 + i * n + j, 1);
                break;
            }
        }

        if (flag) {
            for (int j = 0; j < n; ++j) {
                add_edge(szof(graph) - 1, from1 + i * n + j, 1);
            }
        }

        graph.puba(vector<pii>());
        add_edge(szof(graph) - 1, t, 1);
        flag = true;
        for (int j = 0; j < n; ++j) {
            if (field[j][i] == 'x' || field[j][i] == 'o') {
                flag = false;
                add_edge(from1 + j * n + i, szof(graph) - 1, 1);
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < n; ++j) {
                add_edge(from1 + j * n + i, szof(graph) - 1, 1);
            }
        }
    }

    int from2 = szof(graph);

    graph.resize(szof(graph) + n * n);

    for (int i = 0; i < n * 2 - 1; ++i) {
        int x = i, y = 0;
        if (x >= n) {
            x = n - 1;
            y = i - (n - 1);
        }
        graph.puba(vector<pii>());
        add_edge(s, szof(graph) - 1, 1);
        bool flag = true;
        int mx = x, my = y;
        while (on_field(x, y)) {
            if (field[x][y] == '+' || field[x][y] == 'o') {
                flag = false;
                add_edge(szof(graph) - 1, from2 + x * n + y, 1);
                break;
            }
            x--;
            y++;
        }

        if (flag) {
            x = mx, y = my;
            while (on_field(x, y)) {
                add_edge(szof(graph) - 1, from2 + x * n + y, 1);
                x--;
                y++;
            }
        }

        mx = (n - 1) - mx;

        graph.puba(vector<pii>());
        add_edge(szof(graph) - 1, t, 1);
        flag = true;
        x = mx, y = my;
        while (on_field(x, y)) {
            if (field[x][y] == '+' || field[x][y] == 'o') {
                flag = false;
                add_edge(from2 + x * n + y, szof(graph) - 1, 1);
                break;
            }
            x++;
            y++;
        }

        if (flag) {
            x = mx, y = my;
            while (on_field(x, y)) {
                add_edge(from2 + x * n + y, szof(graph) - 1, 1);
                x++;
                y++;
            }
        }
    }

    while (bfs(s, t)) {
        cnt.resize(szof(graph));
        fill(bend(cnt), 0);
        while (dfs(s, t, INF));
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            field[i][j] = '.';
            int tmp = i * n + j;
            if (szof(graph[from1 + tmp]) && edges[graph[from1 + tmp][0].ss].f) {
                field[i][j] = 'x';
            }
            if (szof(graph[from2 + tmp]) && edges[graph[from2 + tmp][0].ss].f) {
                if (field[i][j] == 'x') {
                    field[i][j] = 'o';
                } else {
                    field[i][j] = '+';
                }
            }
        }
    }

    /*
    cerr << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cerr << field[i][j];
        }
        cerr << endl;
    }*/

    int tot = 0;
    vector<tuple<char, int, int>> ans;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 'x' || field[i][j] == '+') {
                ++tot;
            }
            if (field[i][j] == 'o') {
                tot += 2;
            }
            if (inp[i][j] != field[i][j]) {
                ans.puba({field[i][j], i, j});
            }
        }                                    
    }

    cout << tot << " " << szof(ans) << "\n";

    for (auto t : ans) {
        cout << get<0>(t) << " " << get<1>(t) + 1 << " " << get<2>(t) + 1 << "\n";
    }

    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}