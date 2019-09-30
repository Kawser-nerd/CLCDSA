#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;
vector<int8_t> encode(string const & x) {
    int n = x.size();
    vector<int8_t> y(n);
    repeat (i,n) y[n-i-1] = x[i] - '0';
    return y;
}
vector<int8_t> encode(int x) {
    vector<int8_t> y;
    while (x) {
        y.push_back(x % 10);
        x /= 10;
    }
    return y;
}
void normalize(vector<int8_t> & x) {
    int n = x.size();
    repeat (i,n) {
        while (x[i] < 0) {
            assert (i+1 != n);
            x[i+1] -= 1;
            x[i] += 10;
        }
        while (10 <= x[i]) {
            assert (i+1 != n);
            x[i+1] += 1;
            x[i] -= 10;
        }
    }
    while (not x.empty() and x.back() == 0) x.pop_back();
}
vector<int8_t> add(vector<int8_t> const & x, vector<int8_t> const & y) {
    int n = max(x.size(), y.size());
    vector<int8_t> z(n);
    repeat (i, x.size()) z[i] += x[i];
    repeat (i, y.size()) z[i] += y[i];
    normalize(z);
    return z;
}
vector<int8_t> mul(vector<int8_t> const & x, int8_t k) {
    int n = x.size();
    vector<int8_t> y(n+1);
    repeat (i,n) {
        y[i+1] += x[i] * k / 10;
        y[i  ] += x[i] * k % 10;
    }
    normalize(y);
    return y;
}
bool pred(vector<int8_t> const & n, int k) {
    vector<int8_t> a = mul(add(n, encode(k)), 9);
    return whole(accumulate, a, 0) <= 9 * k;
}
int main() {
    string s; cin >> s;
    vector<int8_t> n = encode(s);
    int l = 0;
    int r = 9 * s.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        (pred(n, m) ? r : l) = m;
    }
    cout << r << endl;
    return 0;
}