#include <bits/stdc++.h>
using namespace std;

int x[100010], y[100010], n;
int dis[110], use[110], fa[110];
set<int> ss[100010];
string s[110];
int ROOT;

void del(int u, int v) {
    if (u == -1 || v == -1) return;
    ss[u].erase(v);
    ss[v].erase(u);
}

void add(int u, int v) {
    if (u == -1 || v == -1) return;
    ss[u].insert(v);
    ss[v].insert(u);
}

void bfs(int u) {
    memset(dis, -1, sizeof(dis));
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto v : ss[x]) {
            if (dis[v] == -1) {
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
}

bool ok(int pre, int xx) {
    int now = pre, cnt = 0;
    while (now != -1) {
        if (ss[now].find(xx) != ss[now].end()) {
            bfs(ROOT);
            for (int i = 0; i < n; i++) {
                if (use[i] == 0 && dis[i] == -1) {
                    for (int j = 0; j < cnt; j++) {
                        add(x[j], y[j]);
                    }
                    return false;
                }
            }
            for (int j = 0; j < cnt; j++) {
                add(x[j], y[j]);
            }
            return true;
        } else {
            int pre = cnt;
            for (auto xx : ss[now]) {
                x[cnt] = now;
                y[cnt++] = xx;
            }
            for (int i = pre; i < cnt; i++) {
                del(x[i], y[i]);
            }
        }
        now = fa[now];
    }
    for (int j = 0; j < cnt; j++) {
        add(x[j], y[j]);
    }
    return false;
}

int get(int pre, int u) {
    while (pre != -1 && ss[pre].find(u) == ss[pre].end()) {
        int cnt = 0;
        for (auto xx : ss[pre]) {
            x[cnt] = pre;
            y[cnt++] = xx;
        }
        for (int i = 0; i < cnt; i++) {
            del(x[i], y[i]);
        }
        pre = fa[pre];
    }
    return pre;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            use[i] = 0;
            ss[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            ss[u].insert(v);
            ss[v].insert(u);
        }
        string ans = "";
        int pre = -1;
        for (int i = 0; i < n; i++) {
            int id = -1;
            string tmp;
            for (int j = 0; j < n; j++) {
                if (use[j]) continue;
                if (i == 0 || ok(pre, j)) {
                    if (id == -1 || tmp > s[j]) {
                        tmp = s[j];
                        id = j;
                    }
                }
            }
            use[id] = 1;
            ans += s[id];
            pre = get(pre, id);
            fa[id] = pre;
            pre = id;
            if (i == 0) {
                ROOT = id;
            }
        }
        printf("Case #%d: %s\n", cas, ans.c_str());
    }
    return 0;
}
