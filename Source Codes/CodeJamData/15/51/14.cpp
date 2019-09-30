#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int s[1000005], p[1000005], c[1000005];
int mn[1000005], mx[1000005];

void gen(int *a, int n) {
    int A, C, R;
    scanf("%d %d %d %d", &a[0], &A, &C, &R);
    FO(i,1,n) {
        a[i] = (a[i-1] * 1ll * A + C) % R;
    }
}

int main() {
    int T; scanf("%d", &T);
    FO(Z,1,T+1) {
        FO(i,0,1000005) c[i] = 0;
        int n,d; scanf("%d %d", &n, &d);
        gen(s,n);
        gen(p,n);
        FO(i,1,n) p[i] = p[i] % i;

        mn[0] = mx[0] = s[0];
        FO(i,1,n) {
            mn[i] = mn[p[i]];
            mx[i] = mx[p[i]];
            mn[i] = min(mn[i], s[i]);
            mx[i] = max(mx[i], s[i]);

            int l = mx[i]-d, r = mn[i]+1;
            l = max(l,0); r = min(r,1000004);
            if (l < r) {
                c[l]++; c[r]--;
            }
        }

        FO(i,1,1000005) c[i] += c[i-1];
        int res = 0;
        FO(i,0,1000005) {
            if (i <= s[0] && s[0] <= i+d) res = max(res, c[i]+1);
        }
        printf("Case #%d: %d\n", Z, res);
    }
}

