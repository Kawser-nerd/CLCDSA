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
    ull a, b, x;
    cin >> a >> b >> x;
    ull ans = (b / x) - (a / x) + 1 - (a % x != 0);
    cout << ans << endl;
}