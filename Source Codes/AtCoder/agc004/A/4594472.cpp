#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << 0 << '\n';
    } else {
        cout << min({a*b, b*c, c*a}) << '\n';
    }

    return 0;
}