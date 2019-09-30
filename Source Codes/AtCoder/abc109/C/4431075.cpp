#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;

static constexpr ull MOD = 1000000007;
static constexpr double pi = 3.14159265359;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> x;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        x.push_back(abs(tmp - X));
    }
    if (N == 1) {
        cout << x[0] << endl;
        return 0;
    }
    int a = x[0];
    for (int i = 1; i < N; ++i) {
        int b = x[i];
        a = gcd(a, b);
    }
    cout << a << endl;
}