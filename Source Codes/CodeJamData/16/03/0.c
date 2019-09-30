#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32
#define J 500
#define MAXD 1000

char seen[J + 10][N + 10];
int divs[J + 10][20];

int test(char *v, int base, int div) {
    int i, rem = 0;
    for (i = 0; i < N; i++) {
        rem = base * rem + v[i]-'0';
        rem %= div;
    }
    return rem == 0;
}

int main() {
    int i, j, repeated, base, found, ok, div;
    int cnt = 0;
    srand(42);
    while (cnt < J) {
        char v[N + 10];
        v[0] = v[N - 1] = '1';
        for (i = 1; i < N - 1; i++)
            v[i] = rand() % 2 ? '1' : '0';
        v[N] = 0;
        repeated = 0;
        for (i = 0; i < cnt; i++) {
            if (strcmp(v, seen[i]) == 0) {
                repeated = 1;
                break;
            }
        }
        if (repeated) continue;

        ok = 1;
        for (base = 2; base <= 10; base++) {
            found = 0;
            for (div = 3; div < MAXD && !found; div += 2) {
                if (test(v, base, div)) {
                    found = 1;
                    divs[cnt][base] = div;
                }
            }
            if (!found) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            strcpy(seen[cnt], v);
            cnt++;
        }
    }
    
    printf("Case #1:\n");
    for (i = 0; i < J; i++) {
        printf("%s", seen[i]);
        for (j = 2; j <= 10; j++)
            printf(" %d", divs[i][j]);
        printf("\n");
    }

    return 0;
}
