#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int , int> P;

int h = 0, w = 0;
char maze[501][501];
int visited[501][501][3] = { 0 };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

P start, goal;

/*
bool dfs(int x, int y, int d) {   // d: ????????

    bool ans;

    visited[x][y] = 1;

    maze[x][y] = 'E';

    cout << endl;
    cout << "d: " << d << endl;

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cnt++;
    cout << "cnt: " << cnt << endl;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j == w - 1) cout << maze[i][j] << endl;
            else            cout << maze[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && visited[nx][ny] == 0) {
            if (maze[nx][ny] == '.') {
                ans = dfs(nx, ny, d);

            } else if (maze[nx][ny] == '#') {
                if (d < 2) {
                    ans = dfs(nx, ny, d);
                }
            } else if (maze[nx][ny] == 'g') {
                ans = true;
                return ans;
            } else {
                return false;
            }
        }
    }

    return ans;
}
*/

bool bfs(int sX, int sY) {
    bool ans = false;

    queue<tuple<int, int , int>> que;

    que.push(make_tuple(sX, sY, 0));

    while (que.size()) {
        int x, y, d;
        tie(x, y, d) = que.front(); que.pop();

        if (x == goal.first && y == goal.second) {
            ans = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (visited[nx][ny][d] == 1) continue;          // ???????
                if (maze[nx][ny] == '#' && d == 2) continue;    // 2????????
                if (maze[nx][ny] == '#' && d < 2) {
                    visited[nx][ny][d + 1] = 1;
                    que.push(make_tuple(nx, ny, d + 1)); 
                } else {
                    visited[nx][ny][d] = 1;
                    que.push(make_tuple(nx, ny, d));
                }
            }
        }
    }

    // while (que.size() && ans) {
    //     P p = que.front(); que.pop();
    //     maze[p.first][p.second] = 'E';

    //     if (p.first == goal.first && p.second == goal.second) {
    //         break;
    //     }

    //     for (int i = 0; i < 4; i++) {
    //         int nx = p.first + dx[i], ny = p.second + dy[i];
    //         if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
    //             if ((maze[nx][ny] == '.' || maze[nx][ny] == 'g') && visited[nx][ny] == 0) {
    //                 que.push(P(nx, ny));
    //                 visited[nx][ny] = 1;
    //             }
                
    //             else if (maze[nx][ny] == '#' && d < 3 && visited[nx][ny] == 0) {
    //                 que.push(P(nx, ny));
    //                 d++;
    //                 visited[nx][ny] = 1;
    //             } else if (maze[nx][ny] == '#' && d >= 2) {
    //                 ans = false;
    //             }
    //         }   
    //     }

    // }

    return ans;
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 's') {
                start.first = i;
                start.second = j;
            }
            if (maze[i][j] == 'g') {
                goal.first = i;
                goal.second = j;
            }
        }
    }

    // cout << (dfs(start.first, start.second, 0) ? "YES" : "NO") << endl;

    cout << (bfs(start.first, start.second) ? "YES" : "NO") << endl;


    return 0;
}