#include <stdio.h>
#include <stdlib.h>

int comp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int size[10005];

int main(void) {
    int t;
    int caso;
    int n, x;

    int i, j;
    int r;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %d %d", &n, &x);

        for (i = 0; i < n; i++) {
            scanf(" %d", &size[i]);
        }

        qsort(size, n, sizeof(int), comp);

        r = 0;
        i = 0;
        j = n - 1;
        while(i <= j) {
            if (size[i] + size[j] <= x) {
                i++;
                j--;
            } else {
                j--;
            }
            r++;
        }

        printf("Case #%d: %d\n", caso, r);
    }
    return 0;
}





