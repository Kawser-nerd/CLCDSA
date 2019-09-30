#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll l, t;
    cin >> n >> l >> t;

    ll x[n];
    int w[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> w[i];

    vector <ll> vec(n);
    for (int i = 0; i < n; i++) {
        if (w[i] == 1) {
            vec[i] = (x[i] + t) % l;
        } else {
            vec[i] = (x[i] - t % l + l) % l;
        }
    }

    ll pos = vec[0];
    sort(vec.begin(), vec.end());

    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (w[0] == 1 && w[i] == 2) {
            ll cnt = t / l * 2;
            if (t%l > (x[i] - x[0]) / 2) cnt++;
            if (t%l > x[i] - x[0] + (l + x[0] - x[i]) / 2) cnt++;
            idx = (idx + cnt) % n;
        } else if (w[0] == 2 && w[i] == 1) {
            ll cnt = t / l * 2;
            if (t%l > l + x[0] - x[i] + (x[i] - x[0]) / 2) cnt++;
            if (t%l > (l + x[0] - x[i]) / 2) cnt++;
            idx = (idx - cnt % n + n) % n;
        }
    }

    int start = 0;
    if (w[0] == 1) {
        for (int i = 0; i < n; i++) {
            if (vec[i] == pos) {
                start = (i - idx + n) % n;
                break;
            }
        }
    } else {
        for (int i = n-1; i >= 0; i--) {
            if (vec[i] == pos) {
                start = (i - idx + n) % n;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << vec[(start + i) % n] << '\n';
    return 0;
}