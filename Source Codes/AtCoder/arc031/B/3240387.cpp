#include <iostream>
#include <vector>

using namespace std;

char island[11][11];
char reclaimedTest[11][11];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {

    reclaimedTest[x][y] = 'E';
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < 10 && y + dy[i] >= 0 && y + dy[i] < 10 && reclaimedTest[x + dx[i]][y + dy[i]] == 'o') {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

bool check(int x, int y) {

    reclaimedTest[x][y] = 'o';
    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (reclaimedTest[i][j] == 'o') {
                dfs(i, j);
                cnt++;
            }
        }
    }

    if (cnt == 1) return true;
    else          return false;
}

void copyArr() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            reclaimedTest[i][j] = island[i][j];
        }
    }
}

int main()
{
    int ans = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> island[i][j];
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (island[i][j] == 'x') {
                copyArr();
                ans = check(i, j);
            }
            if (ans) { break; }
        }
        if (ans) { break; }
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}