#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;

class point {
   public:
    int y, x, v;
    point() {}
    point(int y, int x, int v) : y(y), x(x), v(v) {}
    bool operator<(const point &p) const { return v < p.v; }
};

int main() {
    static int dy[] = {0, 0, 1, -1};
    static int dx[] = {1, -1, 0, 0};

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    vector<point> ps;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ps.push_back(point(i, j, a[i][j]));
        }
    }
    sort(ps.begin(), ps.end());

    vector<vector<int>> dp(h, vector<int>(w, 1));
    for (const point &p : ps) {
        for (int k = 0; k < 4; k++) {
            int y = p.y + dy[k];
            int x = p.x + dx[k];
            if (0 <= y && y < h && 0 <= x && x < w && a[y][x] < p.v) {
                dp[p.y][p.x] += dp[y][x];
                dp[p.y][p.x] %= MOD;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            sum += dp[i][j];
            sum %= MOD;
        }
    }

    cout << sum << endl;

    return 0;
}