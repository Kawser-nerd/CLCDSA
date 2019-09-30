#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int bellmanford(int h, int w, const vector<string>& s, int c) {
    static int dy[] = {1, -1, 0, 0};
    static int dx[] = {0, 0, 1, -1};
    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') {
                sy = i;
                sx = j;
            }
            if (s[i][j] == 'G') {
                gy = i;
                gx = j;
            }
        }
    }

    vector<vector<int>> d(h, vector<int>(w, INF));
    d[sy][sx] = 0;

    bool update = true;
    while (update) {
        update = false;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < 4; k++) {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (!(0 <= y && y < h && 0 <= x && x < w)) {
                        continue;
                    }
                    int v = d[i][j] + (s[y][x] == '#' ? c : 1);
                    if (v < d[y][x]) {
                        d[y][x] = v;
                        update = true;
                    }
                }
            }
        }
    }

    return d[gy][gx];
}

int main() {
    int h, w, t;
    cin >> h >> w >> t;

    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    // [lb, ub)
    int ub = t + 1;
    int lb = 1;
    while (ub - lb > 1) {
        int mid = lb + (ub - lb) / 2;
        if (bellmanford(h, w, s, mid) <= t) {
            lb = mid;
        }else{
            ub = mid;
        }
    }

    cout << lb << endl;

    return 0;
}