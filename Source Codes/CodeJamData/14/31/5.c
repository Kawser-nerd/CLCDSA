#include <stdio.h>
#include <stdlib.h>

long long int gcd (long long int a, long long int b) {
  long long int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int ispow2 (long long int x) {
    while ((x & 1) == 0) x /= 2;
    if (x == 1)
        return 1;
    else
        return 0;
}

int main () {
    int T, t;
    scanf("%d\n", &T);
    for (t = 1; t <= T; t++) {
        long long int P, Q;
        scanf("%lld/%lld\n", &P, &Q);
        long long int g = gcd(P,Q);
        P /= g;
        Q /= g;
        if (ispow2(Q) != 1) {
            printf("Case #%d: impossible\n", t);
        } else {
            int a = 1;
            while (P < Q / 2) {
                a++;
                Q /= 2;
            }
            printf("Case #%d: %d\n", t, a);
        }
        
    }
    return 0;
}
