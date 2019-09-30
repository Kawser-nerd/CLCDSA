#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
double a[51], af[51];
UI N;
double U;
void reset()
{
    for (int i = 0;  i < 51; ++i) a[i] = af[i] = 0.0;
}
double calc()
{
    double hi = 1.0, lo = 0.0, ans = 0.0;
    for (int i = 0; i < 500; ++i) {
        double mid = (lo+hi)/2.0, l = U;
        for (UI n = 1; n <= N; ++n) {
            if (a[n] < mid) {
                l = l - (mid - a[n]);
            }
        }
        ans = mid;
        if (l > 0.0) lo = mid;
        else hi = mid;
        if (abs(hi-lo) < 0.0000000001) break;
    }
    double p = 1.0;
    for (UI n = 1; n <= N; ++n) {
        if (a[n] > ans) p = p*a[n];
        else p = p*ans;
    }
    return p;
}
int main()
{
    freopen("in", "r", stdin);
    UI T;
    cin >> T;
    for (UI t = 1; t <= T; ++t) {
        reset();
        UI K;
        cin >> N >> K;
        cin >> U;
        double td = 0.0;
        for (UI n = 1; n <= N; ++n) {
            cin >> a[n];
            af[n] = 1.0 - a[n];
            td += af[n]; 
        }
        double ans = 0.0;
        if (td <= U) { ans = 1.0; }
        else {
            ans = calc();
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}

