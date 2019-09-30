#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int N;
    while (cin >> N) {
        vector<int> a(N);
        int mx = 1 << 30;
        int bi;
        for (int i = 0; i < N; ++i) {
            int& p = a[i];
            cin >> p;
            if (mx == (1 << 30) || abs(mx) < abs(p)) {
                mx = p;
                bi = i;
            }
        }
        if (mx > 0) {
            cout << 2 * N << endl;
            cout << bi + 1 << ' ' << 1 << endl;
            cout << bi + 1 << ' ' << 1 << endl;
            a[0] += a[bi];
            a[0] += a[bi];
            for (int i = 1; i < N; ++i) {
                cout << i << ' ' << i + 1 << endl;
                cout << i << ' ' << i + 1 << endl;
                a[i] += a[i - 1];
                a[i] += a[i - 1];
            }
        } else if (mx < 0) {
            cout << 2 * N << endl;
            cout << bi + 1 << ' ' << N << endl;
            cout << bi + 1 << ' ' << N << endl;
            a[N - 1] += a[bi];
            a[N - 1] += a[bi];
            for (int i = N - 1; i; --i) {
                cout << i + 1 << ' ' << i << endl;
                cout << i + 1 << ' ' << i << endl;
                a[i - 1] += a[i];
                a[i - 1] += a[i];
            }
        } else {
            cout << 0 << endl;
        }
        for (int i = 1; i < N; ++i)
            if (a[i - 1] > a[i]) U("G");
    }
    return 0;
}