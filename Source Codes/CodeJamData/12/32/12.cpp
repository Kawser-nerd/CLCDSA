
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;

const double EPS = 1e-8;

int T;

double t[2005], x[2005];

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    cin >> T;
    
    for (int cs = 1; cs <= T; ++cs) {
        double D;
        int N, A;
        cin >> D >> N >> A;
        for (int i = 0; i < N; ++i)  
            cin >> t[i] >> x[i];
        for (int i = 0; i + 1 < N; ++i) {
            if (x[i] < D - EPS && x[i + 1] > D + EPS) {
                x[N] = D;
                double k = (x[N] - x[i]) / (x[N] - x[i + 1]);
                t[N] = (t[i] - k * t[i + 1]) / (1 - k);
                ++N;
               // cout << "ds" << t[N - 1] << endl;
                break;
            }
        }
        printf("Case #%d:\n", cs);
        while (A--) {
            double a;
            cin >> a;
            double t0 = 0.0;
            for (int i = 0; i < N; ++i)
                if (x[i] < D + EPS) t0 = max(t0, t[i] - sqrt(2 * x[i] / a));
            printf("%.8f\n", t0 + sqrt(2 * D / a));
        }
    }
    //system("pause");
    return 0;
}
/*
1
3
2 2 3
1 3
0

*/
