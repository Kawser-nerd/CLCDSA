#include <algorithm>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
#define int ll

const int MOD = 1e9 + 7;
const int INF = 1e15 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

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

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (T e : v) {
        os << e << ", ";
    }
    os << "]";
    return os;
}

signed main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    deque<char> q;
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            q.push_back(s[i]);
        } else if (q.front() == s[i]) {
            q.pop_front();
        } else if (q.back() == s[i]) {
            q.pop_back();
        } else {
            if (i == n - 1) {
                q.push_front(s[i]);
            } else if (q.front() == q.back()) {
                q.push_front(s[i]);
            } else if (q.front() == s[i + 1]) {
                q.push_back(s[i]);
            } else if (q.back() == s[i + 1]) {
                q.push_front(s[i]);
            } else {
                q.push_front(s[i]);
            }
        }
    }

    cout << q.size() << endl;

    return 0;
}