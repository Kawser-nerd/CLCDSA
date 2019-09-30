#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

// #define INF 1000000000
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using P       = pair<int, int>;
const int INF = 1LL << 50;

struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} SETUP;

template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

int H, W, N;
vector<vector<char>> g_graph;
vector<vector<int>> g_distance;
const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};

int bbfs(const int sy, const int sx, const int gy, const int gx) {
    g_distance[sy][sx] = 0;
    queue<P> q;
    q.push(P(sy, sx));
    while (!q.empty()) {
        P now = q.front();
        q.pop();
        int y = now.first, x = now.second;
        if (y == gy && x == gx) {
            break;
        }

        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                continue;
            }
            if (g_graph[ny][nx] == 'X') {
                continue;
            }

            bool update = chmin<int>(g_distance[ny][nx], g_distance[y][x] + 1);
            if (update) {
                q.push(P(ny, nx));
            }
        }
    }
    return g_distance[gy][gx];
}

int g_path = 0;

void bfs(const int gy, const int gx) {
    g_distance[0][0] = 0;
    queue<P> q;
    q.push(P(0, 0));
    while (!q.empty()) {
        P now = q.front();
        q.pop();
        int y = now.first, x = now.second;
        if (y == gy && x == gx) {
            break;
        }

        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
                continue;
            }
            if (g_graph[ny][nx] == '#') {
                continue;
            }

            if (chmin(g_distance[ny][nx], g_distance[y][x] + 1)) {
                q.push(P(ny, nx));
                g_graph[ny][nx] = 'o';
            }
        }
    }
}

signed main() {
    cin >> H >> W;
    g_graph.assign(H + 10, vector<char>(W + 10));
    int white = 0;
    rep(i, H) {
        rep(j, W) {
            char c;
            cin >> c;
            g_graph[i][j] = c;
            if (c == '.') {
                white++;
            }
        }
    }

    g_distance.assign(H + 10, vector<int>(W + 10, INF));
    bfs(H - 1, W - 1);
    if (g_distance[H - 1][W - 1] != INF) {
        int ans = white - g_distance[H - 1][W - 1] - 1;
        cout << ans << endl;
    } else {
        puts("-1");
    }
}