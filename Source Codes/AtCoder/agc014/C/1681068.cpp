#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

static int dr[4] = {1, 0, -1, 0},
           dc[4] = {0, 1, 0, -1};

static int H, W, K;

bool inside(int r, int c) {
    return 0 <= r and r < H and 0 <= c and c < W;
}

int main() {
    const int MAXH = 810;
    const int MAXW = 810;

    cin >> H >> W >> K;

    int sr = -1, sc = -1;

    string A[MAXH];
    for (int r = 0; r < H; r++) {
        cin >> A[r];
        for (int c = 0; c < W; c++) {
            if (A[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }

    static int dist[MAXH][MAXW];
    memset(dist, -1, sizeof(dist));

    queue<tuple<int, int, int>> Q;
    dist[sr][sc] = 0;
    Q.push({sr, sc, 0});

    int ans = W * H;
    while (!Q.empty()) {
        int r, c, d;
        tie(r, c, d) = Q.front(); Q.pop();

        int x = min({r, H - 1 - r, c, W - 1 - c});

        ans = min(ans, (x + K - 1) / K + 1);

        if (d == K) continue;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i],
                nc = c + dc[i];
            if (inside(nr, nc) and dist[nr][nc] < 0 and A[nr][nc] != '#') {
                dist[nr][nc] = d + 1;
                Q.push({nr, nc, d + 1});
            }
        }
    }
    cout << ans << endl;

    return 0;
}