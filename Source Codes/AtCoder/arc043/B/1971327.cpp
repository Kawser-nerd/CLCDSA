#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
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
using std::lower_bound;
using std::upper_bound;

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

void dump(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

vector2<int> memo = init_vector2(4, 1e5 + 1, -1);
int search(const vector<int>& a, const vector<int>& p, int d, int i) {
    if (d == 3) {
        return i;
    }
    if (i == 0) {
        return 0;
    }
    if (memo[d][i] != -1) {
        return memo[d][i];
    }

    // int sum = 0;
    // for (int j = 0; j < i; j++) {
    //     sum = (sum + search(a, p, d + 1, p[a[j] / 2])) % MOD;
    // }

    int sum = 0;
    sum = (sum + search(a, p, d, i - 1)) % MOD;
    sum = (sum + search(a, p, d + 1, p[a[i - 1] / 2])) % MOD;
    return memo[d][i] = sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());

    vector<int> p(1e5 + 1);
    for (int i = 0; i <= 1e5; i++) {
        p[i] = upper_bound(a.begin(), a.end(), i) - a.begin();
    }

    printf("%d\n", search(a, p, 0, n));

    return 0;
}