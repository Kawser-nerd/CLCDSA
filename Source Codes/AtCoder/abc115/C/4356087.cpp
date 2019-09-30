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


ull E = 1000000007;
ull e = 10007;
const double pi = 3.14159265359;

int main() {
    ull N, K;
    cin >> N >> K;
    vector<ull> h;
    for (ull i = 0; i < N; ++i) {
        ull tmp;
        cin >> tmp;
        h.push_back(tmp);
    }
    ull ans = 9999999999;
    sort(h.begin(), h.end());
    for (ull i = 0; i + K - 1 < N; ++i) {
        ans = min(ans, h[i + K - 1] - h[i]);
    }
    cout << ans << endl;
}