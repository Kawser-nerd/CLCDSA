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
const double pi = 3.14159265359;

bool check(int n) {
    return (n % 2 != 0) && (n % 3 != 2);
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j) {
            if (check(a - j)) break;
            ++ans;
        }
    }
    cout << ans << endl;
}