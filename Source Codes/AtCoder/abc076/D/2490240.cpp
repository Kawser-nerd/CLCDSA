#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int v[20100];
int t[100];
int mxvv[100];
int mxv[20100];
int n;
int total = 0;
int main(){
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> t[i];
    for (int i = 0; i < n; ++i) cin >> mxvv[i];

    int tt = 0;
    for (int i = 0; i < n; ++i) {
        total += t[i];
        for (; tt < total; ++tt) {
            mxv[tt] = mxvv[i];
            v[tt] = 0;
        }
    }
    mxv[total] = mxvv[n - 1];
    while (1) {
        bool update = false;
        for (int t = 1; t < total; ++t) {
            if (v[t] <= v[t + 1] && v[t] <= v[t - 1] && v[t] < mxv[t] && v[t] < mxv[t - 1]) {
                v[t]++;
                update = true;
            }
        }
        if (!update) break;
    }
    double ans = 0;
    for (int t = 1; t <= total; ++t) {
        ans += (v[t - 1] + v[t]) / 2.;
        if (v[t - 1] == v[t] && v[t] < mxv[t - 1]) ans += 0.25;
    }
    cout << fixed << setprecision(12) << ans << endl;
}