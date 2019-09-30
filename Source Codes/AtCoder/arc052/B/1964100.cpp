#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

double volume(double r, double h) { return r * r * M_PI * h / 3; }

int main() {
    int n, q;
    cin >> n >> q;

    vector<double> x(n);
    vector<double> r(n);
    vector<double> h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i] >> h[i];
    }

    for (int i = 0; i < q; i++) {
        double a, b;
        cin >> a >> b;

        double sum = 0;
        for (int j = 0; j < n; j++) {
            if (x[j] + h[j] < a || b < x[j]) {
                continue;
            }

            sum += volume(r[j], h[j]);
            if (x[j] <= a) {
                double rate = (x[j] + h[j] - a) / h[j];
                sum -= volume(r[j], h[j]) - volume(rate * r[j], rate * h[j]);
            }
            if (b <= x[j] + h[j]) {
                double rate = (x[j] + h[j] - b) / h[j];
                sum -= volume(rate * r[j], rate * h[j]);
            }
        }
        cout << fixed << setprecision(9) << sum << endl;
    }
    return 0;
}