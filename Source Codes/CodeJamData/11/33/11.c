// http://code.google.com/codejam
// Task: 

#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (a && b) {
        if (a < b) b %= a;
        else a %= b;
    }
    return (a+b);
}

long long lcm (long long a, long long b) {
    return a / gcd(a, b) * b;
}


int main ()
{
    int T; // Number of tests
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int N;
        long long int L, H;
        scanf("%d %lld %lld", &N, &L, &H);
        long long int f[N];
        for(int n = 0; n < N; ++n) {
            scanf("%lld", &f[n]);
        }

        long long int s = -1;
        for (long long int i = L; i<=H; ++i) {
            bool possible = true;
            for(int n = 0; n < N; ++n) {
                if (f[n]%i != 0 && i%f[n] != 0) {
//                    printf("!!! %lld  %lld\n", f[n], i);
                    possible = false;
                    break;
                }
            }
            if (possible) {
                s = i;
                break;
            }
        }
        if (s < 0) {
            printf("Case #%d: NO\n", t);
        } else {
            printf("Case #%d: %lld\n", t, s);
        }
    }
    return 0;
}
