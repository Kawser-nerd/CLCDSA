#include <iostream>
#include <vector>
#include <string>

using namespace std;
int h, w;

int main() {
    cin >> h >> w;
    string board[50 + 5];
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < h; i++) {
        cin >> board[i];
    }

    int cnt, x, y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cnt = 0;
            if (board[i][j] == '.') {
                for (int k = 0; k < 8; k++) {
                    x = i + dx[k];
                    y = j + dy[k];
                    if (x >= 0 && x < h && y >= 0 && y < w && board[x][y] == '#') {
                        cnt++;
                    }
                }
                cout << cnt;
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
    return 0;
}