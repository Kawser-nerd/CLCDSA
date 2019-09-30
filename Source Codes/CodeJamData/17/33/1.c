#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("out.txt", "w", stdout)

int n, k;
double u, ar[52], temp[52];

bool check(long double m){
    int i, j;
    long double r = u;

    for (i = 0; i < n; i++){
        if (ar[i] < m){
            r -= (m - ar[i]);
            temp[i] = m;
        }
        else temp[i] = ar[i];
    }
    if (r < 0.0) return false;
    return true;
}

long double solve_small(){
    int i, j;
    long double low = 0.0, high = 1.0;

    for (i = 0; i < 1000; i++){
        long double mid = (low + high) / 2.0;
        if (check(mid)) low = mid;
        else high = mid;
    }

    check(high);

    long double res = 1.0;
    for (i = 0; i < n; i++) res *= temp[i];
    return res;
}

long double solve_large(){
    assert(0);
    return 0;
}

long double solve(){
    if (n == k) return solve_small();
    return solve_large();
}

int main(){
    read();
    write();
    int T = 0, t, i, j;

    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &k);
        scanf("%lf", &u);
        for (i = 0; i < n; i++) scanf("%lf", &ar[i]);

        double res = solve() + 1e-15;
        printf("Case #%d: %0.12f\n", ++T, res);
    }
    return 0;
}
