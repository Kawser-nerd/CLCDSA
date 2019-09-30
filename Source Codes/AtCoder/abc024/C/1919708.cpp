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

int solve(int d, const vector<int>& ls, const vector<int>& rs, int s, int t) {
    // [ll, rr]
    int ll = s;
    int rr = s;
    int ans = -1;
    for (int i = 0; i < d; i++) {
        const int l = ls[i];
        const int r = rs[i];
        if(r < ll || rr < l){
            continue;
        }
        ll = min(ll, l);
        rr = max(rr, r);

        if(ll <= t && t <= rr){
            ans = i + 1;
            break;
        }
    }
    return ans;
}

int main() {
    int n, d, k;
    cin >> n >> d >> k;

    vector<int> ls(d);
    vector<int> rs(d);
    for (int i = 0; i < d; i++) {
        cin >> ls[i] >> rs[i];
    }

    vector<int> ss(k);
    vector<int> ts(k);
    for (int i = 0; i < k; i++) {
        cin >> ss[i] >> ts[i];
    }

    for (int i = 0; i < k; i++) {
        cout << solve(d, ls, rs, ss[i], ts[i]) << endl;
    }

    return 0;
}