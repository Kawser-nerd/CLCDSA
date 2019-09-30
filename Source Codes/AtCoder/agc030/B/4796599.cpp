#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int main() {
    ll L, N;
    cin >> L >> N;

    vector <ll> X(N+1), Y(N+1), Xs(N+1), Ys(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
        Y[N + 1 - i] = L - X[i];
    }
    for (int i = 1; i <= N; i++) {
        Xs[i] = Xs[i - 1] + X[i];
        Ys[i] = Ys[i - 1] + Y[i];
    }

    ll ans = 0;
    for (int d = 0; d <= N; d++) {
        int xt = d, yt = N - d;
        for (int k1 = 0; k1 < 2; k1++) {
            for (int k2 = 0; k2 < 2; k2++) {
                int cx = min(xt, yt + (-dy[k1] - dy[k2] + dx[k1] + dx[k2]) / 2);
                int cy = min(yt, xt + (-dx[k1] - dx[k2] + dy[k1] + dy[k2]) / 2);
                if (cx < 0 || cy < 0) continue;

                ll result = 0;
                result += (Xs[xt] - Xs[xt - cx]) * 2;
                result += (Ys[yt] - Ys[yt - cy]) * 2;
                result -= (k2 ? Y[yt] : X[xt]);
                ans = max(ans, result);
            }
        }
    }
    cout << ans << endl;
    return 0;
}