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

int dist(int base, int num, int i) {
    i -= base;

    int cnt = 0;
    for (int j = 0; j < num; j++) {
        cnt += abs(i + j);
    }

    return cnt;
}

int eval(int r, int g, int b, int gi) {
    int bi = gi + g;
    int center_b = bi + b / 2;
    if (center_b < 100) {
        bi += 100 - center_b;
    }

    int ri = gi - r;
    int center_r = ri + r / 2;
    if (center_r > -100) {
        ri -= center_r - (-100);
    }

    return dist(0, g, gi) + dist(100, b, bi) + dist(-100, r, ri);
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int ans = INF;
    for (int i = -1000; i < 1000; i++) {
        ans = min(ans, eval(r, g, b, i));
    }
    cout << ans << endl;

    return 0;
}