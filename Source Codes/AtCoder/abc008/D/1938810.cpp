#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
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

using std::map;

class point {
   public:
    int x;
    int y;
    point() : x(0), y(0) {}
    point(int x, int y) : x(x), y(y) {}

    bool operator<(const point& p) const {
        if (x == p.x) {
            return y < p.y;
        }
        return x < p.x;
    }
};

vector<point> inners(const vector<point>& ms, const point& s, const point& t) {
    vector<point> ans;
    for (const point& m : ms) {
        if (s.x <= m.x && m.x <= t.x && s.y <= m.y && m.y <= t.y) {
            ans.push_back(m);
        }
    }
    return ans;
}

map<pair<point, point>, int> memo;
int solve(int d, const vector<point>& ms, const point& s, const point& t) {
    if (memo.find(make_pair(s, t)) != memo.end()) {
        return memo[make_pair(s, t)];
    }

    if (ms.size() == 0) {
        return 0;
    }

    int ans = -1;
    for (const point& m : ms) {
        int sum = 1;
        sum += m.x - s.x;
        sum += t.x - m.x;
        sum += m.y - s.y;
        sum += t.y - m.y;

        point ss;
        point tt;

        ss = point(s.x, s.y);
        tt = point(m.x - 1, m.y - 1);
        sum += solve(d + 1, inners(ms, ss, tt), ss, tt);

        ss = point(s.x, m.y + 1);
        tt = point(m.x - 1, t.y);
        sum += solve(d + 1, inners(ms, ss, tt), ss, tt);

        ss = point(m.x + 1, s.y);
        tt = point(t.x, m.y - 1);
        sum += solve(d + 1, inners(ms, ss, tt), ss, tt);

        ss = point(m.x + 1, m.y + 1);
        tt = point(t.x, t.y);
        sum += solve(d + 1, inners(ms, ss, tt), ss, tt);

        ans = max(ans, sum);
    }

    memo.insert(make_pair(make_pair(s, t), ans));
    return ans;
}

int main() {
    int w, h;
    cin >> w >> h;

    int n;
    cin >> n;

    vector<point> ms(n);
    for (int i = 0; i < n; i++) {
        cin >> ms[i].x >> ms[i].y;
    }

    cout << solve(0, ms, point(1, 1), point(w, h)) << endl;

    return 0;
}