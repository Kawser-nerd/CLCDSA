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

double p[55];

int main() {
    srand(31415); ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        int n, k;
        cin >> n >> k;
        double u;
        cin >> u;
        for (int i = 0; i < n; ++i)
            cin >> p[i];
        
        cout << "Case #" << T << ": ";
        
        while (u > 1e-6) {
            sort(p, p + n);
            int i = 0;
            while (i + 1 < n && abs(p[i + 1] - p[i]) < 1e-6) i++;
            if (i + 1 >= n) {
                for (int i = 0; i < n; ++i)
                    p[i] += u / n;
                u = 0;
            } else {
                double diff = (p[i + 1] - p[i]);
                
                double add = min(diff, u / (i + 1));
                for (int j = 0; j <= i; ++j) {
                    p[j] += add;
                    u -= add;
                }
            }
        }
        double res = 1;
        for (int i = 0; i < n; ++i)
            res *= p[i];
        cout.precision(10);
        cout << fixed << res << "\n";
    }
    return 0;
}
