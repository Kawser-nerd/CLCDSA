#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

struct Edge {
    int to;
    int64_t cost;
    Edge(int b, int64_t c) {
        to   = b;
        cost = c;
    }
};

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    std::vector<Edge> edge[1001];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(Edge(b, c));
    }

    int64_t node[1001];
    node[1] = 0;
    for (int i = 2; i <= n; i++) {
        node[i] = -1 * std::pow(10, 13);
    }

    int64_t firstscore = 0, secondscore = 0;

    for (int i = 1; i <= 3 * n; i++) {
        for (int from = 1; from <= n; from++) {
            for (auto x : edge[from]) {
                int64_t before = node[x.to];
                int64_t after  = node[from] + x.cost;
                // cout << before << " " << after << endl;
                if (before < after) {
                    node[x.to] = after;
                }
            }
        }
        if (i == n - 1) {
            firstscore = node[n];
        } else if (i > n - 1) {
            if (node[n] > firstscore) {
                cout << "inf" << endl;
                return 0;
            }
        }
    }
    cout << node[n] << endl;

    return 0;
}