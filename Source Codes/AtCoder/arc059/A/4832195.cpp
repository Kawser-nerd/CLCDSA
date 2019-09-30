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
const ll MOD = 1000000007LL;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int mn = 1e9;
    for (int i = -100; i <= 100; i++) {
        int cost = 0;
        for (int j = 0; j < n; j++) {
            cost += (a[j] - i) * (a[j] - i);
        }
        mn = min(mn, cost);
    }

    cout << mn << "\n";
    return 0;
}