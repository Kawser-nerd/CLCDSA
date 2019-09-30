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

int c1, c2;
int b[2][2222];

int was[1442][2][725][2];

int f(int h, int who, int tm, int frst) {
    if (tm > 720 || h - tm > 720) return 1e9;
    
    if (h == 1440) {
        if (who == frst) return 0;
        return 1;
    }
    
    if (was[h][who][tm][frst] != -1)
        return was[h][who][tm][frst];
    
    int ans = 1e9;
    if (b[who][h+1] == 0)
        ans = min(ans, f(h + 1, who, tm + (who == 0), frst));
    if (b[1 - who][h+1] == 0)
        ans = min(ans, f(h + 1, 1 - who, tm + (who == 1), frst) + 1);
    return was[h][who][tm][frst] = ans;
}

int main() {
    srand(31415); ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        memset(b, 0, sizeof b);
        memset(was, -1, sizeof was);
        
        cin >> c1 >> c2;
        int l, r;
        for (int i = 0; i < c1; ++i) {
            cin >> l >> r;
            for (int j = l + 1; j <= r; ++j)
                b[0][j] = 1;
        }
        for (int i = 0; i < c2; ++i) {
            cin >> l >> r;
            for (int j = l + 1; j <= r; ++j)
                b[1][j] = 1;
        }
        
        cout << "Case #" << T << ": ";
        
        int ans = 1e9;
        if (b[0][0] == 0)
            ans = min(ans, f(1, 0, 1, 0));
        if (b[1][0] == 0)
            ans = min(ans, f(1, 1, 0, 1));
        
        cout << ans << "\n";
    }
    return 0;
}
