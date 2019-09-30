#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
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

    ll n, m;
    cin >> n >> m;

    if (m <= 2 * n) {
        cout << m / 2 << '\n';
    } else {
        cout << n + (m - 2 * n) / 4 << "\n";
    }

    return 0;
}