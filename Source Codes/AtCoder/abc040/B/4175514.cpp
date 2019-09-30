#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;

int main() {
    int n;
    cin >> n;
    int ans = 999999999;
    for (int x = 1; x * x <= n; ++x) {
        for (int y = 1; x * y <= n ; ++y) {
            ans = min(ans, abs(x - y) + (n - x * y));
        }
    }
    cout << ans << endl;
}