#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double root = sqrt(m);
    int res = 1;
    for (int i = 1; i <= root; i++) {
        if (m % i == 0) {
            if (m / n >= i) {
                res = max(res, i);
            }
            if (m / n >= m / i) {
                res = max(res, m / i);
            }
        }
    }
    cout << res << endl;
}