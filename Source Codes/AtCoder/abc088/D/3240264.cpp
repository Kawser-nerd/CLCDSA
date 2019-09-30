#include <iostream>
#include <queue>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int h, w;
char maze[50][51];
int reach[50][50];

int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int sharp;

int bfs() {
    queue<P> que;
    que.push(P(0, 0));
    reach[0][0] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && maze[ny][nx] != '#' && reach[ny][nx] == INT_MAX) {
                que.push(P(ny, nx));
                reach[ny][nx] = min(reach[ny][nx], reach[p.first][p.second] + 1);
            }
        }
    }

    return reach[h - 1][w - 1];
}

int main() {
    cin >> h >> w;
    sharp = 0;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        cin >> maze[i][j];
        reach[i][j] = INT_MAX;
        if (maze[i][j] == '#') ++sharp;
    }

    int ans = bfs();

    if (ans == INT_MAX) cout << -1 << endl;
    else                cout << h * w - ans - sharp - 1 << endl;

    return 0;
}