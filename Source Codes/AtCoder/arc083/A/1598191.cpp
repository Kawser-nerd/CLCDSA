#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int A, B, C, D, E, F;

int dp[3001][3001]; // dp[x][y]: x in y

int main() {
    cin >> A >> B >> C >> D >> E >> F;

    for (int j = 0; j <= 3000; ++j) fill(dp[j], dp[j]+3000, 0);
    dp[0][0] = 1;

    int jj = 0, kk = 100*A;
    for (int j = 0; j <= F; ++j) {
        for (int k = j; k <= F; ++k) {
            if (j < k && dp[j][k] == 1 && j * 100 <= E * (k-j)) {
                // jj / kk < j / k
                if (jj * k < j * kk) {
                    jj = j; kk = k;
                }
            }

            if (dp[j][k] == 0) continue;
            if (k + 100*A <= F) {
                dp[j][k+100*A] = 1;
            }
            if (k + 100*B <= F) {
                dp[j][k+100*B] = 1;
            }

            if (k + C <= F) {
                dp[j+C][k+C] = 1;
            }
            if (k + D <= F) {
                dp[j+D][k+D] = 1;
            }
        }
    }

    cout << kk << " "<< jj << endl;
    return 0;
}