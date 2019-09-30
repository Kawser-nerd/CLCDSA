#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1 << 29;

int n;
char q[32];
int a[32];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i] >> a[i];
    }
}

int dp[1 << 15];
int go(int mask) {
    if (!mask) return 0;
    
    int &ans = dp[mask];
    if (ans != -1) return ans;
    
    ans = INF;
    for (int i = mask; i > 0; i = (i - 1) & mask) {
        int p = -1, bad = 0;
        char prev = -1;
        
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                if (p != -1 && a[j] && p != a[j]) {
                    bad = 1;
                }
                if (a[j]) p = a[j];
                
                if (prev == -1) {
                    prev = q[j];
                } else {
                    if (prev == q[j]) bad = 1;
                    prev = q[j];
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                if (a[j] == p) {
                    bad = 1;
                }
            }
        }
        
        if (bad) continue;
        
        ans = min(ans, go(mask ^ i) + (prev == 'E'));
    }
    
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int ans = go((1 << n) - 1);
    if (ans == INF) printf ("CRIME TIME\n");
    else printf ("%d\n", ans);
}

int main() {
    int cases;
    
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }
    
    return 0;
}
