#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i, a, N) for(int i = a; i < N; i++)

char board[100][100];
int h, w;

bool check(int x, int y) {
    rep(d, -1, 2) {
        if (d == 0) continue;
        int nx = x + d;
        int ny = y + d;
        if (0 <= nx && nx < h)
            if (board[nx][y] == '#') return true;
        if (0 <= ny && ny < w)
            if (board[x][ny] == '#') return true;
    }
    return false;
}

int main() {
    cin >> h >> w;

    int cnt = 0;
    rep(i, 0, h)
        rep(j, 0, w)
            cin >> board[i][j];

    rep(x, 0, h) {
        rep(y, 0, w) {
            if (board[x][y] == '#') {
                if (check(x, y)) continue;
                else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
}