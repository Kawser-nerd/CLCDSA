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

void dump(vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    // [s[i], t[i]]
    vector<int> s(m);
    vector<int> t(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> t[i];
        s[i]--;
        t[i]--;
    }

    vector<int> a(n + 1);
    for (int i = 0; i < m; i++) {
        a[s[i]]++;
        a[t[i] + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    // dump(a);

    for (int i = 0; i <= n; i++) {
        a[i] = a[i] >= 2 ? 1 : 0;
    }

    // dump(a);

    int k = 0;
    int i = 0;
    while (i <= n) {
        if (a[i]) {
            k++;
            while (i <= n && a[i]) {
                a[i] = k;
                i++;
            }
        }
        i++;
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (a[s[i]] != 0 && a[t[i]] != 0 && a[s[i]] == a[t[i]]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (int i : ans) {
        cout << i << endl;
    }

    return 0;
}