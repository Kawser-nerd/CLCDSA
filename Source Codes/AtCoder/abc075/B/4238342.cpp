#include <iostream>
#include <string>
#include <vector>
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {
    int nx, ny;
    vector<int> dxs = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> dys = {1, 1, 0, -1, -1, -1, 0, 1};

    int h, w; cin >> h >> w;
    vector<string> grid(h);
    rep (i, h) cin >> grid[i];

    vector<vector<int>> ans(h);
    rep (i, h) {
        ans[i].resize(w);
        fill(ans[i].begin(), ans[i].end(), 0);
    }

    rep (i, h) {
        rep (j, w) {
            rep (k, 8) {
                nx = i + dxs[k];
                ny = j + dys[k];
                if (nx < 0 or ny < 0) continue;
                if (h <= nx or w <= ny) continue;
                if (grid[nx][ny] == '#') {
                    ans[i][j]++;
                }
            }
        }
    }

    rep (i, h) {
        rep (j, w) {
            if (grid[i][j] == '#') {
                cout << '#';
            }
            else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}