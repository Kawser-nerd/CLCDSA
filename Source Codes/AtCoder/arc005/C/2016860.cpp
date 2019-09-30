#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
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

class union_find_tree {
   private:
    vector<int> p;
    vector<int> h;
    vector<int> w;

   public:
    union_find_tree(int n) : p(n, -1), h(n, 0), w(n, 1) {}

    int find(int u) {
        if (p[u] == -1) {
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(int u, int v) {
        const int u_rt = find(u);
        const int v_rt = find(v);

        if (u_rt == v_rt) {
            return;
        }

        if (h[u_rt] > h[v_rt]) {
            p[v_rt] = u_rt;
            w[u_rt] += w[v_rt];
        } else {
            p[u_rt] = v_rt;
            w[v_rt] += w[u_rt];
            if (h[u_rt] == h[v_rt]) {
                h[v_rt]++;
            }
        }
    }

    int weight(int u) { return w[find(u)]; }
    bool same(int u, int v) { return find(u) == find(v); }
};

static vector<int> dy4 = {0, 0, 1, -1};
static vector<int> dx4 = {1, -1, 0, 0};

bool in_range(int n, int x) { return 0 <= x && x < n; }
bool in_range2(int h, int w, int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

vector<bool> make_table(union_find_tree& uft, int h, int w,
                        const vector<string>& c, int sy, int sx) {
    vector<bool> ans(h * w);

    ans[uft.find(sy * w + sx)] = true;
    rep(i, h) {
        rep(j, w) {
            if (c[i][j] != '#') {
                continue;
            }

            bool found = false;
            rep(k, 4) {
                int y = i + dy4[k];
                int x = j + dx4[k];
                if (!in_range2(h, w, y, x)) {
                    continue;
                }
                if (c[y][x] == '.' && uft.same(sy * w + sx, y * w + x)) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                continue;
            }

            ans[uft.find(i * w + j)] = true;
            rep(k, 4) {
                int y = i + dy4[k];
                int x = j + dx4[k];
                if (in_range2(h, w, y, x) && c[y][x] == '.') {
                    ans[uft.find(y * w + x)] = true;
                }
            }
        }
    }
    return ans;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> c(h);
    rep(i, h) { cin >> c[i]; }

    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    rep(i, h) {
        rep(j, w) {
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

    c[sy][sx] = '.';
    c[gy][gx] = '.';

    union_find_tree uft(h * w);
    rep(i, h) {
        rep(j, w) {
            if (c[i][j] != '.') {
                continue;
            }
            rep(k, 4) {
                int y = i + dy4[k];
                int x = j + dx4[k];
                if (in_range2(h, w, y, x) && c[y][x] == '.') {
                    uft.unite(i * w + j, y * w + x);
                }
            }
        }
    }

    vector<bool> stbl = make_table(uft, h, w, c, sy, sx);
    vector<bool> gtbl = make_table(uft, h, w, c, gy, gx);

    bool ans = false;
    rep(i, h) {
        rep(j, w) {
            if (stbl[i * w + j] && gtbl[i * w + j]) {
                ans = true;
                break;
            }
            rep(k, 4) {
                int y = i + dy4[k];
                int x = j + dx4[k];
                if (in_range2(h, w, y, x) && stbl[i * w + j] &&
                    gtbl[y * w + x]) {
                    ans = true;
                    goto out;
                }
            }
        }
    }
out:

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}