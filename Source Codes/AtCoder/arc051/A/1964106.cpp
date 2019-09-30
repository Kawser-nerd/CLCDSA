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

bool inner(int x, int y, int r, int a, int b) {
    int dx = abs(x - a);
    int dy = abs(y - b);
    return dx * dx + dy * dy <= r * r;
}

const int INF = 1e9 + 314;

int main() {
    int x1, y1, r;
    cin >> x1 >> y1 >> r;

    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;

    bool red = !(x2 <= x1 - r && x1 + r <= x3 && y2 <= y1 - r && y1 + r <= y3);
    bool blue = !(inner(x1, y1, r, x2, y2) && inner(x1, y1, r, x3, y3) &&
                  inner(x1, y1, r, x2, y3) && inner(x1, y1, r, x3, y2));

    cout << (red ? "YES" : "NO") << endl;
    cout << (blue ? "YES" : "NO") << endl;

    return 0;
}