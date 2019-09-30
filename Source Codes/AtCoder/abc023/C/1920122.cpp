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

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    int n;
    cin >> n;

    vector<int> rs(n);
    vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        cin >> rs[i] >> cs[i];
        rs[i]--;
        cs[i]--;
    }

    vector<int> r_cnt(r);
    vector<int> c_cnt(c);
    for (int i = 0; i < n; i++) {
        r_cnt[rs[i]]++;
        c_cnt[cs[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (r_cnt[rs[i]] + c_cnt[cs[i]] == k) {
            ans--;
        }
        if (r_cnt[rs[i]] + c_cnt[cs[i]] - 1 == k) {
            ans++;
        }
    }

    sort(r_cnt.begin(), r_cnt.end());

    for (int l : c_cnt) {
        ans += std::upper_bound(r_cnt.begin(), r_cnt.end(), k - l) -
               std::lower_bound(r_cnt.begin(), r_cnt.end(), k - l);
    }

    cout << ans << endl;

    return 0;
}