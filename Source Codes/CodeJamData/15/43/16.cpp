#include<map>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2 + (1000 * 2 + 10 * 200) * 2 + 200 + 5,
          M = 500005;
int source, target, n;

#define next NEXT

const int INF = 1000000000;

int top, head[N], to[M], next[M], c[M];

void addEdge(int u, int v, int cap) {
    to[top] = v, next[top] = head[u], c[top] = cap, head[u] = top++;
}

int dis[N], gap[N];

bool over;

int go(int u, int delta) {
    if (u == target) {
        return delta;
    }

    int t = delta, tmp;
    for (int i = head[u]; ~i; i = next[i]) {
        if (c[i]) {
            int v = to[i];
            if (dis[v] == dis[u] - 1) {
                tmp = min(t, c[i]);
                tmp = go(v, tmp);
                t -= tmp;
                c[i] -= tmp;
                c[i ^ 1] += tmp;
                if (over || t == 0) {
                    return delta - t;
                }
            }
        }
    }
    if (--gap[dis[u]] == 0) {
        over = true;
    }
    ++gap[++dis[u]];
    return delta - t;
}

int flow(int n) {
    for (int i = 0; i <= n; ++i) {
        dis[i] = gap[i] = 0;
    }
    over = false;
    int ret = 0;
    while (!over && dis[source] < n) {
        ret += go(source, INF);
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<string> lines[n];
        int dictid = 1;
        map<string, int> tr;
        char buf[1000 * 11 + 5];
        gets(buf);
        for (int i = 0; i < n; ++i) {
            gets(buf);
            string cur = "";
            int l = strlen(buf);
            for (int j = 0; j < l; ++j) {
                if (buf[j] == ' ') {
                    lines[i].push_back(cur);
                    if (!tr.count(cur)) {
                        tr[cur] = dictid++;
                    }
                    cur = "";
                } else {
                    cur += buf[j];
                }
            }
            lines[i].push_back(cur);
            if (!tr.count(cur)) {
                tr[cur] = dictid++;
            }
        }
        source = 0, target = 1;
        memset(head, -1, sizeof(int) * (n - 2 + 2 * dictid));
        top = 0;
        for (int i = 1; i < dictid; ++i) {
            addEdge(i * 2, i * 2 + 1, 1);
            addEdge(i * 2 + 1, i * 2, 1);
        }
        for (int i = 0; i < lines[0].size(); ++i) {
            addEdge(source, tr[lines[0][i]] * 2, INF);
            addEdge(tr[lines[0][i]] * 2, source, 0);
        }
        for (int i = 0; i < lines[1].size(); ++i) {
            addEdge(tr[lines[1][i]] * 2 + 1, target, INF);
            addEdge(target, tr[lines[1][i]] * 2 + 1, 0);
        }
        for (int i = 2; i < n; ++i) {
            int u = 2 * dictid + i - 2;
            for (int j = 0; j < lines[i].size(); ++j) {
                int vid = tr[lines[i][j]];
                addEdge(u, vid * 2, INF);
                addEdge(vid * 2, u, 0);
                addEdge(vid * 2 + 1, u, INF);
                addEdge(u, vid * 2 + 1, 0);
            }
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, flow(dictid * 2 + n - 2));
    }
    return 0;
}
