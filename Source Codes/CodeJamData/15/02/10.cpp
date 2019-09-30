#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int n; scanf("%d", &n);
        vector<int> v(n);
        FO(i,0,n) scanf("%d", &v[i]);
        int res = 1e9;
        for (int d = 1; d <= 1000; d++) {
            int s = 0;
            for (int x : v) s += (x-1) / d;
            res = min(res, s+d);
        }
        printf("Case #%d: %d\n", Z, res);
    }
}

