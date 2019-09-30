#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int T, A, B, tc, n, m, c, h, t;
    scanf("%d", &T);
    for(tc=1; tc<=T; ++tc) {
        scanf("%d %d", &A, &B);
        c = 0;
        h = 1;
        t = A;
        while (t /= 10) h *= 10;
        for(n=A; n<B; ++n) {
            m = n;
            do {
                m = m / 10 + h * (m % 10);
                if(n < m) {
                    if(m <= B) {
                        ++c;
                    }
                }
            } while(m != n);
        }
        printf("Case #%d: %d\n", tc, c);
    }
    return 0;
}

