#include <algorithm>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#ifdef __APPLE__
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif

const int N = (int)820;
const int MOD = (int)1e9 + 7;
const int inf = (int)5e8;
const long long infll = (long long)1e17;

char f[N][N];

int dist[N][N];
int used_locks[N][N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int h, w, k;

bool in_board(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

bool opened[N][N];
bool reached[N][N];

void solve() {
    scanf("%d %d %d", &h, &w, &k);
    int x, y;
    for (int i = 0; i < h; ++i) {
        scanf("%s", f[i]);
        for (int j = 0; j < w; ++j) {
            dist[i][j] = inf;
            if (f[i][j] == 'S') {
                x = i;
                y = j;
            }
            opened[i][j] = f[i][j] != '#';
        }
    }
    reached[x][y] = true;
    for (int iter = 1;; ++iter) {
        vector<pair<int, int>> qu;
        vector<vector<int>> dist(h, vector<int>(w, inf));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (reached[i][j]) {
                    dist[i][j] = 0;
                    qu.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < qu.size(); ++i) {
            int x = qu[i].first;
            int y = qu[i].second;
            if (dist[x][y] == k) {
                continue;
            }
            for (int j = 0; j < 4; ++j) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if (in_board(xx, yy)) {
                    if (opened[xx][yy]) {
                        if (dist[xx][yy] > dist[x][y] + 1) {
                            dist[xx][yy] = dist[x][y] + 1;
                            reached[xx][yy] = true;
                            qu.push_back({xx, yy});
                        }
                    }
                }
            }
        }
        qu.clear();
        vector<vector<int>> dist1(h, vector<int>(w, inf));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (reached[i][j]) {
                    dist1[i][j] = 0;
                    qu.push_back({i, j});
                }
            }
        }
        for (int i = 0; i < qu.size(); ++i) {
            int x = qu[i].first;
            int y = qu[i].second;
            if (dist1[x][y] == k) {
                continue;
            }
            for (int j = 0; j < 4; ++j) {
                int xx = x + dx[j];
                int yy = y + dy[j];
                if (in_board(xx, yy)) {
                    if (dist1[xx][yy] > dist1[x][y] + 1) {
                        dist1[xx][yy] = dist1[x][y] + 1;
                        opened[xx][yy] = true;
                        qu.push_back({xx, yy});
                    }
                }
            }
        }
        for (int i = 0; i < h; ++i) {
            if (reached[i][0] || reached[i][w - 1]) {
                printf("%d\n", iter);
                return;
            }
        }
        for (int i = 0; i < w; ++i) {
            if (reached[0][i] || reached[h - 1][i]) {
                printf("%d\n", iter);
                return;
            }
        }
    }
}

int main() {
#ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}