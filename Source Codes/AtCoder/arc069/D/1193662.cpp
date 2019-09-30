#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>

constexpr int MAX_N = 20100;

constexpr int TREE = 2 * MAX_N;

constexpr int MAX_NODES = TREE + 4 * MAX_N;

using namespace std;

int n;
int x[MAX_N], y[MAX_N];

vector<pair<int, int>> events;

vector<int> adj[MAX_NODES];
vector<int> inv_adj[MAX_NODES];

bool is_node[MAX_NODES];
bool vis1[MAX_NODES];
bool vis2[MAX_NODES];
int comp[MAX_NODES];

inline int opposite(int i) {
    return i < n ? (i + n) : (i - n);
}

void init_edges(int i, int a, int b) {
    if (b < a) {
        return;
    } else if (a == b) {
        is_node[TREE + i] = true;
        adj[TREE + i].push_back(opposite(events[a].second));
        inv_adj[opposite(events[a].second)].push_back(TREE + i);
    } else {
        is_node[TREE + i] = true;
        adj[TREE + i].push_back(TREE + 2 * i + 1);
        adj[TREE + i].push_back(TREE + 2 * i + 2);
        inv_adj[TREE + 2 * i + 1].push_back(TREE + i);
        inv_adj[TREE + 2 * i + 2].push_back(TREE + i);
        init_edges(2 * i + 1, a, (a + b) / 2);
        init_edges(2 * i + 2, (a + b) / 2 + 1, b);
    }
}

void add_edge(int i, int a, int b, int u, int l, int r) {
    if (b < l || r < a || b < a || r < l) {
        return;
    } else if (a >= l && b <= r) {
        adj[u].push_back(TREE + i);
        inv_adj[TREE + i].push_back(u);
    } else {
        add_edge(2 * i + 1, a, (a + b) / 2, u, l, r);
        add_edge(2 * i + 2, (a + b) / 2 + 1, b, u, l, r);
    }
}

void dfs1(int u, vector<int> &sorted) {
    if (!is_node[u] || vis1[u]) return;
    vis1[u] = true;
    for (int v : adj[u]) {
        dfs1(v, sorted);
    }
    sorted.push_back(u);
}

void dfs2(int u, int c) {
    if (vis2[u]) return;
    vis2[u] = true;
    comp[u] = c;
    for (int v : inv_adj[u]) {
        dfs2(v, c);
    }
}

bool works(int val) {
    for (int i = 0; i < MAX_NODES; i++) {
        is_node[i] = false;
        vis1[i] = false;
        vis2[i] = false;
        adj[i].clear();
        inv_adj[i].clear();
    }

    for (int i = 0; i < 2 * n; i++) {
        is_node[i] = true;
    }

    init_edges(0, 0, 2 * n - 1);

    for (int i = 0; i < 2 * n; i++) {
        pair<int, int> event = events[i];

        int idx1 = distance(events.begin(), lower_bound(events.begin(),
                    events.end(), make_pair(event.first - val + 1, 0)));
        int idx2 = distance(events.begin(), lower_bound(events.begin(),
                    events.end(), make_pair(event.first + val, 0))) - 1;

        add_edge(0, 0, 2 * n - 1, event.second, idx1, i - 1);
        add_edge(0, 0, 2 * n - 1, event.second, i + 1, idx2);
    }

    vector<int> sorted;
    for (int i = 0; i < MAX_NODES; i++) {
        if (is_node[i] && !vis1[i]) {
            dfs1(i, sorted);
        }
    }

    int cc = 0;
    for (int i = sorted.size() - 1; i >= 0; i--) {
        if (!vis2[sorted[i]]) {
            dfs2(sorted[i], ++cc);
        }
    }

    for (int i = 0; i < n; i++) {
        if (comp[i] == comp[i + n]) {
            return false;
        }
    }

    return true;
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &x[i]);
        scanf(" %d", &y[i]);
    }

    for (int i = 0; i < n; i++) {
        events.push_back(make_pair(x[i], i));
        events.push_back(make_pair(y[i], i + n));
    }

    sort(events.begin(), events.end());

    int lo = 0;
    int hi = 1000000000;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", lo);

    return 0;
}