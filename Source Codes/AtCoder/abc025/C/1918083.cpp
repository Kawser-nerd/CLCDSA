#include <algorithm>
#include <complex>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::pair;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

pair<int, int> eval(vector<vector<int>>& a, const vector<vector<int>>& b,
                    const vector<vector<int>>& c) {
    int p0 = 0;
    int p1 = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == a[i + 1][j]) {
                p0 += b[i][j];
            } else {
                p1 += b[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] == a[i][j + 1]) {
                p0 += c[i][j];
            } else {
                p1 += c[i][j];
            }
        }
    }

    return pair<int, int>(p0, p1);
}

pair<int, int> backtrack(vector<vector<int>>& a, const vector<vector<int>>& b,
                         const vector<vector<int>>& c, int d, int t) {
    if (d >= 9) {
        return eval(a, b, c);
    }

    pair<int, int> ans(-INF, -INF);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 0) {
                continue;
            }
            a[i][j] = t;

            pair<int, int> tmp = backtrack(a, b, c, d + 1, -t);
            if (t == 1 && tmp.first > ans.first) {
                ans = tmp;
            }
            if (t == -1 && tmp.second > ans.second) {
                ans = tmp;
            }

            a[i][j] = 0;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> a(3, vector<int>(3));

    vector<vector<int>> b(2, vector<int>(3));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> c(3, vector<int>(2));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> c[i][j];
        }
    }

    pair<int, int> ans = backtrack(a, b, c, 0, 1);

    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;
}