#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

// l?????????????????????
bool eval(int n, int m, const vector<string>& c, int sy, int sx, int gy, int gx,
          double l) {
    static const vector<int> dy = {-1, 1, 0, 0};
    static const vector<int> dx = {0, 0, -1, 1};

    vector2<bool> visited = init_vector2(n, m, false);

    int t = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));

    while (not q.empty()) {
        queue<pair<int, int>> q_next;

        while (not q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;

            rep(k, 4) {
                int yy = y + dy[k];
                int xx = x + dx[k];
                if (not(0 <= yy && yy < n && 0 <= xx && xx < m)) {
                    continue;
                }
                if (visited[yy][xx]) {
                    continue;
                }
                if (c[yy][xx] == '#') {
                    continue;
                }
                if (1.0 * (c[yy][xx] - '0') * pow(0.99, t + 1) >= l) {
                    q_next.push(make_pair(yy, xx));
                }
            }
        }
        t++;
        q = q_next;
    }

    return visited[gy][gx];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> c(n);
    rep(i, n) { cin >> c[i]; }

    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    rep(i, n) {
        rep(j, m) {
            if (c[i][j] == 's') {
                sy = i;
                sx = j;
            }
            if (c[i][j] == 'g') {
                gy = i;
                gx = j;
            }
        }
    }

    // [lb, ub)
    double lb = 0;
    double ub = 10;
    rep(i, 50) {
        double mid = lb + (ub - lb) / 2;
        if (eval(n, m, c, sy, sx, gy, gx, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    if (not eval(n, m, c, sy, sx, gy, gx, -1)) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(16) << lb << endl;
    }

    return 0;
}