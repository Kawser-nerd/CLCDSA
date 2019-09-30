#include <iostream>

using namespace std;
using ull = unsigned long long;

int a[8] = {1,1,2,3,5,8,13,21};

int h, w, k;

int mv[8][8];
ull dp[8][105];

void fillmv() {
    for (int i = 0; i < w - 1; i++) {
        mv[i][i + 1] = mv[i + 1][i] = a[i] * a[w - i - 2];
    }
    for (int i = 0; i < w; i++) {
        mv[i][i] = a[i] * a[w - i - 1];
    }
}

int main() {
    cin >> h >> w >> k;
    fillmv();
    dp[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            ull tmp = 0;
            for (int k = j - 1; k <= j + 1; k++) {
                if (k >= 0 && k < w) {
                    tmp += dp[k][i - 1] * mv[k][j];
                }
            }
            dp[j][i] = tmp % 1000000007;
        }
    }

    cout << dp[k - 1][h] << endl;
}