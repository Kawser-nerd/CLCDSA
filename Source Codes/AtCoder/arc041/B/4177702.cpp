#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>

using namespace std;
int n, m;
int grid[500][500];
int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, -1, 0, 1};
    for (int i = 0; i < m; ++i) cout << 0;
    cout << endl;
    for (int i = 1; i < n - 1; ++i) {
        cout << 0;
        for (int j = 1; j < m - 1; ++j) {
            int mn = 10;
            for (int k = 0; k < 4; ++k) {
                int ni = di[k] + i;
                int nj = dj[k] + j;
                if (grid[ni][nj] < mn) mn = grid[ni][nj];
            }
            for (int k = 0; k < 4; ++k) {
                int ni = di[k] + i;
                int nj = dj[k] + j;
                grid[ni][nj] -= mn;
            }
            cout << mn;
        }
        cout << 0;
        cout << endl;
    }
    for (int i = 0; i < m; ++i) cout << 0;
    cout << endl;
}