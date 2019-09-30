#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

const int maxN = 310;

using namespace std;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

LL check[maxN][maxN], n, d[maxN][maxN], c[maxN][maxN], res;

int main() {
    cin >> n;
    FORU(i, 1, n)
        FORU(j, 1, n) cin >> c[i][j], d[i][j] = c[i][j];
    FORU(t, 1, n)
        FORU(u, 1, n)
            FORU(v, 1, n)
                if (u != t && v != t && u != v)
                    if (d[u][t] + d[t][v] <= d[u][v]) {
                        d[u][v] = d[u][t] + d[t][v];
                        check[u][v] = 1;
                    }
    FORU(i, 1, n)
        FORU(j, 1, n) {
            if (d[i][j] != c[i][j]) { cout << -1; return 0; }
            if (!check[i][j]) res += d[i][j];
        }
    cout << res / 2;
}