#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
UI N, K;
double PI = 3.141592653589793;
vector<pair<double, double> > a;
double dp[1001][1001];
double solve(int i, int k)
{
    if (k == 0 || i >= N) return 0.0;
    if (dp[i][k]) return dp[i][k];
    double ta1 = PI*a[i].first*a[i].first, ta2 =  2*PI*a[i].first*a[i].second ;
    double mx = ta1 + ta2;
    for (int j = i+1; j < N; ++j) {
        double ta = ta1 + ta2 - PI*a[j].first*a[j].first; 
        double a1 = solve(j, k-1) + ta; 
        double a2 = solve(j, k);
        double amax = max(a1, a2);
        mx = max(mx, amax);
    }
    dp[i][k] = mx;
    return mx;
}
int main()
{
    freopen("in", "r", stdin);
    UI T;
    cin >> T;
    for (UI t = 1; t <= T; ++t) {
        a.clear();
        for (UI i = 0; i < 1001; ++i) for (UI j = 0; j < 1001; ++j) dp[i][j] = 0.0;
        cin >> N >> K;
        for (UI n = 0; n < N; ++n) {
            double r, h;
            cin >> r >> h;
            pair<double, double> px(r, h);
            a.push_back(px);
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        double ans = solve(0, K);
        cout << "Case #" << t << ": " << setprecision(40) << ans << endl;
    }
    return 0;
}


