#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n, p, q, r, ss;
long long a[1 << 20];
long long s[1 << 20];

void read() {
    scanf("%d%d%d%d%d", &n, &p, &q, &r, &ss);
}

long long gets(int l, int r) {
    if (!l) return s[r];
    return s[r] - s[l - 1];
}

void ch(long long &ans, int q, int w) {
    if (0 <= q && q <= w && w < n) {
        long long cur = 0;
        
        if (q > 0) cur = max(cur, gets(0, q - 1));
        if (w < n - 1) cur = max(cur, gets(w + 1, n - 1));
        cur = max(cur, gets(q, w));
        
        ans = min(ans, cur);
        
    //    printf ("%d %d   %lld   %lld\n", q, w, cur, gets(q, w));
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        a[i] = ((long long)i * (long long)p + (long long)q) % (long long)r + ss;
        s[i] = a[i];
        
        if (i) {
            s[i] += s[i - 1];
        }
   //     printf ("%lld ", a[i]);
    }
  //  printf ("\n");
    
    long long ans = s[n - 1];
    ans = min(ans, max(s[n - 2], a[n - 1]));
    for (int i = 0; i + 1 < n; i++) {
        int l, r, mid;
        
        l = i + 1;
        r = n - 1;
        
        while (l < r) {
            mid = l + (r - l + 1) / 2;
            
            if (gets(mid, n - 1) > gets(i, mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        
    //    printf ("%d %d\n", i, l);

        ch(ans, i, l - 2);
        ch(ans, i, l - 1);
        ch(ans, i, l);
        ch(ans, i, l + 1);
        ch(ans, i, l + 2);
    }
    
    ans = s[n - 1] - ans;
    printf ("%.15lf\n", (double)ans / (double)s[n - 1]);
}

int main() {
    int cases;
    
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }

    return 0;
}
