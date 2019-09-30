//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>

using namespace std;

int n;
int r[1111], h[1111], id[1111];

double mem[1111][1111][2];

int cmp(int i, int j) {
    return r[i] > r[j];
}

double f(int pos, int need, bool was = 0) {
    if (n - pos < need) return -1e18;
    if (need == 0) return 0.0;
    
    if (mem[pos][need][was] > 0)
        return mem[pos][need][was];
    
    double res = f(pos + 1, need, was);
    
    double gg = 2.0 * M_PI * r[id[pos]] * h[id[pos]];
    if (!was) {
        gg += r[id[pos]] * 1ll * r[id[pos]] * M_PI;
    }
    res = max(res, f(pos + 1, need - 1, 1) + gg);
    return mem[pos][need][was] = res;
}

int main() {
    srand(31415); ios::sync_with_stdio(0);
     freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        int k;
        cin >> n >> k;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= k; ++j)
                mem[i][j][0] = mem[i][j][1] = -1e18;
        for (int i = 0; i < n; ++i) {
            cin >> r[i] >> h[i];
            id[i] = i;
        }
        cout << "Case #" << T << ": ";
        sort(id, id + n, cmp);
        
        cout.precision(10);
        cout << fixed << f(0, k) << "\n";
    }
    return 0;
}
