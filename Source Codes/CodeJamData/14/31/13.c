#include <stdio.h>

long long int gcd(long long int a, long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) {
    int t;
    int caso;
    long long int p;
    long long int q;
    long long int mdc;
    long long int aux;
    int time;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %lld/%lld", &p, &q);

        printf("Case #%d: ", caso);
        if (p > q) {
            printf("impossible\n");
        } else {
            mdc = gcd(q, p);
            q /= mdc;
            p /= mdc;
            time = 1;
            aux = q;
            while(aux % 2 == 0) {
                aux /= 2;
            }
            if (aux != 1) {
                printf("impossible\n");
            } else {
                while(p < q / 2) {
                    time++;
                    q /= 2;
                }
                if (time > 40) {
                    printf("impossible\n");
                } else {
                    printf("%d\n", time);
                }
            }
        }
    }
    return 0;
}


