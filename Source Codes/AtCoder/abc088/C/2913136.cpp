#include <iostream>
#include <algorithm>

using namespace std;

int grid[3][3] = {};

int main() {
    int maxC = -1;
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
        int c; cin >> c;
        maxC = max(maxC, c);
        grid[i][j] = c;
    }

    bool ok = false;
    for (int i = 0; i <= maxC; ++i) {
        for (int j = 0; j <= maxC; ++j) {
            for (int k = 0; k <= maxC; ++k) {
                bool b1, b2, b3;
                b1 = b2 = b3 = false;
                b1 = grid[0][0] - i == grid[1][0] - j && grid[1][0] - j == grid[2][0] - k;
                b2 = grid[0][1] - i == grid[1][1] - j && grid[1][1] - j == grid[2][1] - k;
                b3 = grid[0][2] - i == grid[1][2] - j && grid[1][2] - j == grid[2][2] - k;
                ok = b1 && b2 && b3;
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) break;
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}