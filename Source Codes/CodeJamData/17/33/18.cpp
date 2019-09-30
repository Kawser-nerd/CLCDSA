#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <cmath>
using namespace std;

const double EPS = 1e-9;

int n, k;
double u;
vector<double> p;

void Solve() {
    if (n != k) {
        cout << "I'm not supposed to solve such a problem" << endl;
        return;
    }
    sort(p.begin(), p.end());
    while (true) {
        int r = 0;
        while (r + 1 < n && fabs(p[r + 1] - p[r]) < EPS) {
            ++r;
        }
        if (r == n - 1 && fabs(p[0] - 1.0) < EPS) {
            break;
        }
        if (fabs(u) < EPS) {
            break;
        }
        double delta;
        if (r == n - 1) {
            delta = 1.0 - p[0];
        } else {
            delta = p[r + 1] - p[0];
        }
        const int count = r + 1;
        delta = min(delta, u / count);
        for (int i = 0; i <= r; ++i) {
            p[i] += delta;
        }
        u -= delta * count;
    }
    double result = 1.0;
    for (double cp : p) {
        result *= cp;
    }
    cout << fixed << setprecision(15) << result << endl;
}

void Read() {
    cin >> n >> k >> u;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        Read();
        cout << "Case #" << test << ": ";
        Solve();
    }

    return 0;
}
