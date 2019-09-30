#include <algorithm>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

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

bool win(const vector<string>& a, char t) {
    static vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};
    static vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};

    rep(i, 19) {
        rep(j, 19) {
            if (a[i][j] != t) {
                continue;
            }
            rep(k, 8) {
                int cnt = 0;
                for (int y = i, x = j;
                     0 <= y && y < 19 && 0 <= x && x < 19 && a[y][x] == t;
                     y += dy[k], x += dx[k]) {
                    cnt++;
                }
                if (cnt >= 5) {
                    return true;
                }
            }
        }
    }
    return false;
}

int state(const vector<string>& a) {
    bool b_win = win(a, 'o');
    bool w_win = win(a, 'x');

    if (!b_win && !w_win) {
        return 0;
    }
    if (b_win && !w_win) {
        return 1;
    }
    if (!b_win && w_win) {
        return 2;
    }
    if (b_win && w_win) {
        return 3;
    }
    return -1;
}

bool solve(vector<string>& a) {
    int w_cnt = 0;
    int b_cnt = 0;
    rep(i, 19) {
        rep(j, 19) {
            if (a[i][j] == 'o') {
                b_cnt++;
            } else if (a[i][j] == 'x') {
                w_cnt++;
            }
        }
    }

    if (b_cnt != w_cnt && b_cnt != w_cnt + 1) {
        return false;
    }

    bool turn = b_cnt == w_cnt;  // true: black, false: white

    switch (state(a)) {
        case 0:
            return true;
        case 3:
            return false;
        case 1: {
            if (turn) {
                return false;
            }
            rep(i, 19) {
                rep(j, 19) {
                    if (a[i][j] != 'o') {
                        continue;
                    }

                    a[i][j] = '.';
                    if (state(a) == 0) {
                        return true;
                    }
                    a[i][j] = 'o';
                }
            }
            return false;
        }

        case 2: {
            if (!turn) {
                return false;
            }

            rep(i, 19) {
                rep(j, 19) {
                    if (a[i][j] != 'x') {
                        continue;
                    }

                    a[i][j] = '.';
                    if (state(a) == 0) {
                        return true;
                    }
                    a[i][j] = 'x';
                }
            }
            return false;
        }
    }
    return false;
}

signed main() {
    vector<string> a(19);
    rep(i, 19) { cin >> a[i]; }
    cout << (solve(a) ? "YES" : "NO") << endl;

    return 0;
}