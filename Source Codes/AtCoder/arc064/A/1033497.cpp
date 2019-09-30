#include<iostream>
#include<vector>
using namespace std;

int main() {
    int64_t N, x;
    cin >> N >> x;
    vector<int64_t> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < N; ++i) {
        if (x < a[i]) {
            ans += a[i] - x;
            a[i] = x;
        }
    }

    for(int i = 0; i < N - 1; ++i) {
        if (x < a[i] + a[i + 1]) {
            int64_t t = a[i] + a[i + 1] - x;
            ans += t;
            a[i + 1] -= t;
            if (a[i + 1] < 0) {
                a[i + 1] = 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}