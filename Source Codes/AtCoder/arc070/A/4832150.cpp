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
    int X;
    cin >> X;

    int ans = 1;
    while (ans * (ans + 1) / 2 < X) {
        ans++;
    }

    cout << ans << "\n";
    return 0;
}