#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    double T[n+1];
    T[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        T[i] += T[i-1];
    }

    double v[n];
    for (int i = 0; i < n; i++) cin >> v[i];

    double ans = 0.0;
    double before = 0.0;
    for (double t = 0.5; t <= T[n]; t += 0.5) {
        double mn = 1234567.0;
        mn = min(mn, t);
        mn = min(mn, T[n] - t);

        for (int i = 0; i < n; i++) {
            if (t < T[i]) {
                mn = min(mn, v[i] + T[i] - t);
            } else if (t < T[i+1]) {
                mn = min(mn, v[i]);
            } else {
                mn = min(mn, v[i] + t - T[i+1]);
            }
        }

        ans += (before + mn) * 0.25;
        before = mn;
    }

    cout << fixed << setprecision(10) <<  ans << "\n";
    return 0;
}