#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int B = 1010, INF = 1000000000;
vector<pair<int, int> > edge[B];
int w, h, b, x1[B], y1[B], x2[B], y2[B], dis[B];

int cal(int l0, int r0, int l1, int r1) {
    int l = max(l0, l1), r = min(r0, r1);
    if (r >= l) {
        return 0;
    } else {
        return l - r;
    }
}
int cal(int i, int j) {
    int dx = cal(x1[i], x2[i] + 1, x1[j], x2[j] + 1), dy = cal(y1[i], y2[i] + 1, y1[j], y2[j] + 1);
    return max(dx, dy);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        static int id = 0;
        printf("Case #%d: ", ++id);
        scanf("%d%d%d", &w, &h, &b);
        edge[0].push_back(make_pair(1, w));
        edge[1].push_back(make_pair(0, w));
        for (int i = 0; i < b; ++i) {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            edge[0].push_back(make_pair(i + 2, x1[i]));
            edge[i + 2].push_back(make_pair(0, x1[i]));
            edge[1].push_back(make_pair(i + 2, w - x2[i] - 1));
            edge[i + 2].push_back(make_pair(1, w - x2[i] - 1));
            for (int j = 0; j < i; ++j) {
                int d = cal(i, j);
                edge[i + 2].push_back(make_pair(j + 2, d));
                edge[j + 2].push_back(make_pair(i + 2, d));
            }
        }
        for (int i = 0; i < b + 2; ++i) {
            dis[i] = INF;
        }
        priority_queue<pair<int, int> > heap;
        dis[0] = 0;
        heap.push(make_pair(0, 0));
        while (heap.size()) {
            int u = heap.top().second, d = -heap.top().first;
            heap.pop();
            if (dis[u] != d) {
                continue;
            }
            for (int j = 0; j < (int)edge[u].size(); ++j) {
                int v = edge[u][j].first, nd = d + edge[u][j].second;
                if (nd < dis[v]) {
                    dis[v] = nd;
                    heap.push(make_pair(-dis[v], v));
                }
            }
        }
        printf("%d\n", dis[1]);
        for (int i = 0; i < b + 2; ++i) {
            edge[i].clear();
        }
    }
    return 0;
}
