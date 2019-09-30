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

int main() {
    string n;
    cin >> n;
    for (char c : n) {
        if (c == '1') cout << 9;
        else if (c == '9') cout << 1;
        else cout << c;
    }
    cout << endl;
}