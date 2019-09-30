#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        static int id = 0;
        printf("Case #%d: ", ++id);
        int n;
        double v, x;
        scanf("%d%lf%lf", &n, &v, &x);
        vector<pair<double, double> > taps;
        for (int i = 0; i < n; ++i) {
            double r, c;
            scanf("%lf%lf", &r, &c);
            taps.push_back(make_pair(c, r));
        }
        sort(taps.begin(), taps.end());
        if (taps[0].first > x || taps.back().first < x) {
            printf("IMPOSSIBLE\n");
        } else {
            double sumT = 0, sumV = 0;
            for (int i = 0; i < n; ++i) {
                sumT += taps[i].first * taps[i].second;
                sumV += taps[i].second;
            }
            for (int i = n - 1; i >= 0 && sumT / sumV > x + 1e-9; --i) {
                double r = taps[i].second, c = taps[i].first;
                if ((sumT - r * c) / (sumV - r) > x + 1e-9) {
                    sumT -= r * c;
                    sumV -= r;
                } else {
                    double ll = 0, rr = r;
                    for (int i = 0; i < 50; ++i) {
                        double mid = (ll + rr) / 2;
                        if ((sumT - mid * c) / (sumV - mid) > x) {
                            ll = mid;
                        } else {
                            rr = mid;
                        }
                    }
                    sumT -= ll * c;
                    sumV -= ll;
                    break;
                }
            }
            for (int i = 0; i < n && sumT / sumV < x - 1e-9; ++i) {
                double r = taps[i].second, c = taps[i].first;
                if ((sumT - r * c) / (sumV - r) < x - 1e-9) {
                    sumT -= r * c;
                    sumV -= r;
                } else {
                    double ll = 0, rr = r;
                    for (int i = 0; i < 50; ++i) {
                        double mid = (ll + rr) / 2;
                        if ((sumT - mid * c) / (sumV - mid) < x) {
                            ll = mid;
                        } else {
                            rr = mid;
                        }
                    }
                    sumT -= ll * c;
                    sumV -= ll;
                    break;
                }
            }
            printf("%.10f\n", v / sumV);
        }
    }
    return 0;
}
