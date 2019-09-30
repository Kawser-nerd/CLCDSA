#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

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

void conv(string& s, const vector<int>& table) {
    int n = s.length();
    rep(i, n) { s[i] = table[s[i] - '0'] + '0'; }
}

bool comp(const string& s, const string& t) {
    ll a = stoi(s);
    ll b = stoi(t);
    return a < b;
}

int main() {
    vector<int> b(10);
    rep(i, 10) { cin >> b[i]; }

    vector<int> inv_b(10);
    rep(i, 10) { inv_b[b[i]] = i; }

    int n;
    cin >> n;

    vector<string> a(n);
    rep(i, n) { cin >> a[i]; }

    rep(i, n) { conv(a[i], inv_b); }

    sort(a.begin(), a.end(), comp);

    rep(i, n) { conv(a[i], b); }

    rep(i, n) { cout << a[i] << endl; }

    return 0;
}