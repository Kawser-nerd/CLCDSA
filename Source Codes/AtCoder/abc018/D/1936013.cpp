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
using std::swap;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

class edge {
   public:
    int to;
    int w;
    edge() : to(0), w(0) {}
    edge(int to, int w) : to(to), w(w) {}
};

int popcnt(int n) { return __builtin_popcount(n); }

int main() {
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;

    vector<vector<edge>> g(n);
    for (int i = 0; i < r; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back(edge(y, z));
    }

    int ans = -1;

    for (int s = 0; s < (1 << n); s++) {
        if (popcnt(s) != p) {
            continue;
        }

        vector<int> v(m);
        for (int i = 0; i < n; i++) {
            if (!(s & (1 << i))) {
                continue;
            }
            for (const edge& e : g[i]) {
                v[e.to] += e.w;
            }
        }

        sort(v.begin(), v.end(), std::greater<int>());

        int sum = 0;
        for (int i = 0; i < q; i++) {
            sum += v[i];
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}