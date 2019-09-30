#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long ll;

vector<vector<ll>> memo(51, vector<ll>(51, -1));

ll comb(ll n, ll r) {
    if(memo[n][r] > 0){
        return memo[n][r];
    }
    if(n <= r){
        return 1;
    }
    if(r == 0){
        return 1;
    }
    return memo[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}

int main(void) {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<ll> acc(v);  // sum of [i, n)
    for (int i = n - 1; i > 0; i--) {
        acc[i - 1] += acc[i];
    }

    ll opt_num = -1;
    for (int i = a; i <= b; i++) {
        if (opt_num == -1 || acc[n - i] * opt_num > acc[n - opt_num] * i) {
            opt_num = i;
        }
    }

    cout << std::fixed << std::setprecision(8);
    cout << (1.0 * acc[n - opt_num] / opt_num) << endl;

    ll cnt = 0;
    for (int i = a; i <= b; i++) {
        if (acc[n - i] * opt_num != acc[n - opt_num] * i) {
            continue;
        }
        ll key = v[n - i];
        ll cntIn = 0;
        for (int j = n - i; j < n; j++) {
            if (v[j] == key) {
                cntIn++;
            }
        }

        ll cntOut = 0;
        for (int j = 0; j < n - i; j++) {
            if (v[j] == key) {
                cntOut++;
            }
        }
        cnt += comb(cntIn + cntOut, cntIn);
    }

    cout << cnt << endl;

    return 0;
}