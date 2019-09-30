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

    if (n % 2 == 0) {
        int m = n * (n + 1) / 2;
        int d = m / (n / 2);

        cout << n * (n - 2) / 2 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (i + j != d) {
                    cout << i << " " << j << '\n';
                }
            }
        }
    } else {
        cout << (n * (n - 2) + 1) / 2 << "\n";

        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (i + j != n) {
                    cout << i << " " << j << '\n';
                }
            }
        }
    }

    return 0;
}