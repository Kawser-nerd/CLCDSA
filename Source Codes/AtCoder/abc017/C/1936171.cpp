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

class range {
   public:
    int l;
    int r;
    int s;
    range() : l(0), r(0), s(0) {}
    range(int l, int r, int s) : l(l), r(r), s(s) {}
};

std::ostream& operator<<(std::ostream& os, const range& r) {
    os << "[" << r.l << "," << r.r << "," << r.s << "]";
    return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    for (T e : v) {
        os << e << " ";
    }
    return os;
}

bool comp_l(const range& r0, const range& r1) { return r0.l > r1.l; }
bool comp_r(const range& r0, const range& r1) { return r0.r < r1.r; }

int main() {
    int n, m;
    cin >> n >> m;

    vector<range> rs(n);
    for (int i = 0; i < n; i++) {
        int l, r, s;
        cin >> l >> r >> s;
        l--;
        r--;
        rs[i] = range(l, r, s);
    }

    sort(rs.begin(), rs.end(), comp_r);
    vector<int> lsum(m);
    for (int i = 0, j = 0, sum = 0; i < m; i++) {
        while (j < n && rs[j].r < i) {
            sum += rs[j].s;
            j++;
        }
        lsum[i] = sum;
    }

    sort(rs.begin(), rs.end(), comp_l);
    vector<int> rsum(m);
    for (int i = m - 1, j = 0, sum = 0; i >= 0; i--) {
        while (j < n && rs[j].l > i) {
            sum += rs[j].s;
            j++;
        }
        rsum[i] = sum;
    }

    int ans = -1;
    for (int i = 0; i < m; i++) {
        ans = max(ans, lsum[i] + rsum[i]);
    }
    cout << ans << endl;

    return 0;
}