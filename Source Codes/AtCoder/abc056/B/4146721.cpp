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


int main() {
    int W, a, b;
    cin >> W >> a >> b;
    if (a + W < b) {
        cout << b - (a + W) << endl;
    } else if (b + W < a) {
        cout << a - (b + W) << endl;
    } else {
        cout << 0 << endl;
    }
}