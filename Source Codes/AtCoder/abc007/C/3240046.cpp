#include <iostream>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

char maze[50][51];
int reach[50][50];

int r, c, sy, sx, gy, gx;

int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};

int bfs() {
    queue<pair<int, int> > que;
    que.push(pair<int, int>(sy, sx));
    reach[sy][sx] = 0;

    while(que.size()) {
        pair<int, int> point = que.front();
        que.pop();

        if (point.first == gy && point.second == gx) break;

        for (int i = 0; i < 4; ++i) {
            int ny = point.first + dy[i], nx = point.second + dx[i];
            if (0 <= ny && ny < r && 0 <= nx && nx < c && maze[ny][nx] != '#' && reach[ny][nx] == INT_MAX) {
                que.push(pair<int, int>(ny, nx));
                reach[ny][nx] = reach[point.first][point.second] + 1;
            }
        }
    }

    return reach[gy][gx];
}

int main() {
    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;

    --sy, --sx, --gy, --gx;

    for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
        cin >> maze[i][j];
        reach[i][j] = INT_MAX;
    }

    cout << bfs() << endl;

    return 0;
}