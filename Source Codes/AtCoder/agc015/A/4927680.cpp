#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a > b) {
        cout << 0 << "\n";
    } else if (n == 1) {
        cout << (b == a ? 1 : 0) << "\n";
    } else {
        cout << (a + (n - 1) * b) - ((n - 1) * a + b) + 1 << "\n";
    }
    return 0;
}