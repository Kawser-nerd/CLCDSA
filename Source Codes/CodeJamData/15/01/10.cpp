#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        int n; char buf[2000];
        scanf("%d %s", &n, buf);
        int c = 0, res = 0;
        FO(i,0,n+1) {
            int d = max(0,i-c);
            res += d; c += d;
            c += buf[i]-'0';
        }
        printf("Case #%d: %d\n", Z, res);
    }
}

