#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N;
    int D, K;
    cin >> N >> D >> K;
    ll l[D], r[D], cur[K], t[K];
    vector<int> ans(K);
    for (int i = 0; i < D; i++) {
        ll a, b;
        cin >> a >> b;
        l[i] = a - 1;
        r[i] = b - 1;
    }
    for (int i = 0; i < K; i++) {
        ll a, b;
        cin >> a >> b;
        cur[i] = a - 1;
        t[i] = b - 1;
    }

    for (int j = 0; j < K; j++) {
        for (int i = 0; i < D; i++) {
            if (l[i] <= cur[j] && cur[j] <= r[i]) {
                if (l[i] <= t[j] && t[j] <= r[i]) {
                    ans[j] = i;
                    break;
                }
                if (cur[j] < t[j]) {
                    cur[j] = r[i];
                } else {
                    cur[j] = l[i];
                }
            }
        }
    }

    for (int i = 0; i < K; i++) cout << ans[i] + 1 << endl;

    return 0;
}