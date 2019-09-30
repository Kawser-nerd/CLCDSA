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

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int main() {
    int n;
    double a, b;
    cin >> n >> a >> b;

    vector<double> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    double s_min = s[0];
    double s_max = s[0];
    for (int i = 1; i < n; i++) {
        s_min = min(s_min, s[i]);
        s_max = max(s_max, s[i]);
    }

    double d = s_max - s_min;
    if (d == 0) {
        cout << -1 << endl;
        return 0;
    }

    double p = b / d;
    for (int i = 0; i < n; i++) {
        s[i] = p * s[i];
    }

    double s_sum = 0;
    for (int i = 0; i < n; i++) {
        s_sum += s[i];
    }

    double q = (n * a - s_sum) / n;

    cout << fixed << setprecision(15) << p << " " << q << endl;

    return 0;
}