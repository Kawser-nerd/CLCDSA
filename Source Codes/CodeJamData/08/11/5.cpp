#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int a[800], b[800];

int main () {
    int t, i, ct;
    
    ct = 0;
    for (scanf("%d", &t); t > 0; t --) {
        scanf("%d", &n);
        for (i = 0; i < n; i ++)
            scanf("%d", a + i);
        for (i = 0; i < n; i ++)
            scanf("%d", b + i);
        sort(a, a + n);
        sort(b, b + n);
        long long ans = 0;
        
        for (i = 0; i < n; i ++)
            ans += a[i] * (long long) b[n - 1 - i];
        
        cout << "Case #" << ++ ct << ": " << ans << endl;
        }
    
    return 0;
    }
