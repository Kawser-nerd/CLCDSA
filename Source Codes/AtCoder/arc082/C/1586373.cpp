#include <iostream>

using namespace std;
const int g = 998244353;

int main() {
    int n, x[200], y[200], p[201];
    cin >> n;
    p[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        p[i+1] = p[i] * 2 % g;
    }
    int a = p[n];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int d = 0;
            for(int k = j + 1; k - n; k++) {
                d += (x[j] - x[i]) * (y[k] - y[i]) == (x[k] - x[i]) * (y[j] - y[i]);
            }
            a = (a + g - p[d]) % g;
        }
    }
    cout << (a + g - 1 - n) % g << endl;
    return 0;
}