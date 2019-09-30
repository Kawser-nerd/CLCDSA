#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

vector<string> grid;
vector<string> target;

void dfs(int i, int j) {
    target[i][j] = 'x';
    for (int k = 0; k < 4; ++k) {
        int ny = i - vy[k], nx = j + vx[k];
        if (ny >= 0 && ny < 10 && nx >= 0 && nx < 10) {
            if (target[ny][nx] == 'o') {
                dfs(ny, nx);
            }
        }
    }
}

bool check() {
    for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) if (target[i][j] == 'o') return false;
    return true;
}

int main() {
    grid.resize(10);
    for (int i = 0; i < 10; ++i) cin >> grid[i];
   
    bool ok = false;
    for (int i = 0; i < 10 && !ok; ++i) {
        for (int j = 0; j < 10 && !ok; ++j) {
            target = grid;
            dfs(i, j);
            ok = check();
        }
    }

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}