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
    int a, b;

    cin >> n;
    cin >> a >> b;

    if (a >= n) {
        cout << "Takahashi" << endl;
        return 0;
    }

    if (a > b) {
        cout << "Takahashi" << endl;
        return 0;
    }

    if (a < b) {
        cout << "Aoki" << endl;
        return 0;
    }

    int m = (n - 1) % (a + 1);
    cout << (m == a ? "Aoki" : "Takahashi") << endl;

    return 0;
}