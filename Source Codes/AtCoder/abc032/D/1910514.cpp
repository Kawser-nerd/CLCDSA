#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
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

typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 7;

class item {
   public:
    ll v;
    ll w;
    item() {}
    item(ll v, ll w) : v(v), w(w) {}

    bool operator<(const item& i) const {
        if (w == i.w) {
            return v > i.v;
        }
        return w < i.w;
    }
};

ll solve1(vector<item>& is, ll n, ll w) {
    int m0 = n / 2;
    int m1 = n - n / 2;

    vector<item> is0;
    vector<item> is1;

    for (ll s = 0; s < (1 << m0); s++) {
        ll sum_v = 0;
        ll sum_w = 0;
        for (ll i = 0; i < m0; i++) {
            if (s & (1 << i)) {
                sum_v += is[i].v;
                sum_w += is[i].w;
            }
        }
        is0.push_back(item(sum_v, sum_w));
    }

    for (ll s = 0; s < (1 << m1); s++) {
        ll sum_v = 0;
        ll sum_w = 0;
        for (ll i = 0; i < m1; i++) {
            if (s & (1 << i)) {
                sum_v += is[m0 + i].v;
                sum_w += is[m0 + i].w;
            }
        }
        is1.push_back(item(sum_v, sum_w));
    }

    sort(is1.begin(), is1.end());
    ll j = 1;
    for (size_t i = 0; i < is1.size(); i++) {
        if (is1[j - 1].w < is1[i].w && is1[j - 1].v < is1[i].v) {
            is1[j++] = is1[i];
        }
    }
    is1.resize(j);

    ll ans = -1;
    for (const item& i0 : is0) {
        if (i0.w > w) {
            continue;
        }
        ll ind = upper_bound(is1.begin(), is1.end(), item(0, w - i0.w)) -
                 is1.begin();
        ans = max(ans, i0.v + is1[ind - 1].v);
    }

    return ans;
}

ll solve2(const vector<item>& is, ll n, ll w) {
    ll sum_w = 0;
    for (ll i = 0; i < n; i++) {
        sum_w += is[i].w;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(sum_w + 1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= sum_w; j++) {
            ll ans = dp[i - 1][j];
            if (j - is[i - 1].w >= 0) {
                ans = max(ans, dp[i - 1][j - is[i - 1].w] + is[i - 1].v);
            }
            dp[i][j] = ans;
        }
    }
    return dp[n][min(w, sum_w)];
}

ll solve3(const vector<item>& is, ll n, ll w) {
    ll sum_v = 0;
    for (ll i = 0; i < n; i++) {
        sum_v += is[i].v;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(sum_v + 1, INF));
    for(ll i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= sum_v; j++) {
            ll ans = dp[i-1][j];
            if(j - is[i-1].v >= 0){
                ans = min(ans, dp[i-1][j-is[i-1].v] + is[i-1].w);
            }else{
                ans = min(ans, is[i-1].w);
            }
            dp[i][j] = ans;
        }
    }

    ll ans = -1;
    for(ll j = sum_v; j >= 0; j--){
        if(dp[n][j] <= w){
            ans = j;
            break;
        }
    }

    return ans;
}

int main() {
    ll n, w;
    cin >> n >> w;

    bool small_v = true;
    bool small_w = true;

    vector<item> is(n);
    for (ll i = 0; i < n; i++) {
        cin >> is[i].v >> is[i].w;
        if (is[i].v > 1000) {
            small_v = false;
        }
        if (is[i].w > 1000) {
            small_w = false;
        }
    }

    if (n <= 30) {
        cout << solve1(is, n, w) << endl;
    } else if (small_w) {
        cout << solve2(is, n, w) << endl;
    } else if (small_v) {
        cout << solve3(is, n, w) << endl;
    } else {
        cout << "undef" << endl;
    }

    return 0;
}