#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;

int N, M;
LL a[1 << 16][16];
int g[16][16];

/// void oper(int a, int b) {
///     g[a][b] = 1;
///     for (int j = 0; j < N; ++j) {
///         if (g[b][j]) {
///             oper(a, j);
///         }
///     }
/// }

int main() {
    cin >> N >> M;

    for (int j = 0; j < N; ++j) {
        fill(g[j], g[j] + N, 0);
    }

    int x[256], y[256];

    for (int j = 0; j < M; ++j) {
        cin >> y[j] >> x[j];
        --x[j]; --y[j];
        g[x[j]][y[j]] = 1;
    }

///    for (int j = 0; j < M; ++j) {
///        oper(x[j], y[j]);
///    }

    for (int j = 0; j < (1 << 16); ++j) {
        fill(a[j], a[j] + 16, 0);
    }

    for (int j = 0; j < N; ++j) {
        a[1 << j][j] = 1;
    }

    for (int b = 2; b <= N; ++b) {
        for (int j = 0; j < (1 << N); ++j) {
            int bc = 0, t = j;
            while (t > 0) { bc += (t % 2); t /= 2; }
            if (bc != b) { continue; }

            for (int k = 0; k < N; ++k) {
                if ((j & (1 << k)) == 0) { continue; }

                for (int l = 0; l < N; ++l) {
                    if (l == k) { continue; }
                    bool ng = false;
                    for (int m = 0; m < N; ++m) {
                        if ((j & (1 << m)) && g[m][k]) { ng = true; }
                    }
                    if (ng) { continue; }

                    a[j][k] += a[j ^ (1 << k)][l];
                }
            }
        }
    }

    LL s = 0;
    for (int j = 0; j < N; ++j) {
        s += a[(1 << N) - 1][j];
    }
    cout << s << endl;

    return 0;
}