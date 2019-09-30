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
const int MOD = 1e9 + 7;

ll pow10_ll(ll m) {
    ll ans = 1;
    for (ll i = 0; i < m; i++) {
        ans *= 10;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;

    const ll len = s.length();

    vector<ll> memo(11);
    for (int i = 1; i <= 10; i++) {
        memo[i] = 10 * memo[i - 1] + pow10_ll(i - 1);
    }

    ll fixed1cnt = 0;
    ll cnt = 0;
    for (int k = 0; k < len; k++) {
        const ll d = s[k] - '0';
        cnt += d * memo[len - k - 1] + d * fixed1cnt * pow10_ll(len - k - 1);
        if (d > 1) {
            cnt += pow10_ll(len - k - 1);
        }
        if (d == 1) {
            fixed1cnt++;
        }
    }

    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}