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

const int maxN = 3010;

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

int a, b, c, d, e, f, g[maxN][maxN], res1, res2;

double density(int i, int j) {
    return (100.0 * j) / (100.0 * i + j);
}

int main() {
    g[0][0] = 1;
    cin >> a >> b >> c >> d >> e >> f;
    FORU(i, 0, f / 100)
        FORU(j, 0, e * i) {
            if (i * 100 + j > f) break;
            if (i >= a)
                g[i][j] |= g[i - a][j];
            if (i >= b)
                g[i][j] |= g[i - b][j];
            if (j >= c)
                g[i][j] |= g[i][j - c];
            if (j >= d)
                g[i][j] |= g[i][j - d];
            if (g[i][j])
                if ((res1 == 0 && res2 == 0) || density(res1, res2) <= density(i, j))
                    res1 = i, res2 = j;
        }
    cout << res1 * 100 + res2 << " " << res2;
}