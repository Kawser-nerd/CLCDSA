#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, a, n) for (int i = a; i < (n); i++)
#define all(in) in.begin(), in.end()
const int INF = 1e9;
const int MOD = 1e9 + 7;
int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int ans = 0;
    for (int i = 0; i <= A; i++) {
        for (int k = 0; k <= B; k++) {
            for (int j = 0; j <= C; j++) {
                int sum = 500 * i + 100 * k + 50 * j;
                if (sum == X) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}