#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IS_VOW(c) ((c)=='a' || (c)=='e' ||(c)=='i' ||(c)=='o'||(c)=='u')
#define IS_CON(c) (!IS_VOW(c))

long long solve_case(char *s, int n)
{
    int *a;
    int *b;
    int i, j, l;
    int prev;
    int seq = 0;
    long long total = 0;

    l = strlen(s);
    a = (int *) calloc(sizeof(int), l);
    b = (int *) calloc(sizeof(int), l);

    for (i = 0; i < l; i++) {
        if (IS_CON(s[i])) {
            seq++;
        } else {
            seq = 0;
        }
        a[i] = seq;
    }

    prev = -1;
    for (i = l - 1; i >= 0; i--) {
        if (a[i] == 0) {
            b[i] = prev;
            continue;
        }

        if (a[i] < n) {
            b[i] = prev;
            continue;
        }

        /* a[i] >= n */
        for (j = 0; j < n - 1; j++, i--)
            b[i] = prev;

        for (; a[i] > 0; i--)
            b[i] = i + (n - 1);
        i++;
        
        prev = i + n - 1;

        if (a[prev] != n)
            printf("error!\n"); // assert
    }

#if 0
    for (i = 0; i < l; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < l; i++)
        printf("%d ", b[i]);
    printf("\n");
#endif
    for (i = 0; i < l; i++) {
        if (b[i] == -1)
            continue;
        total += l-b[i];
    }

    free(a);
    free(b);
    return total;
}

int main()
{
    int ncase, i, n;
    char *s;
    long long r;

    s=(char*) malloc(sizeof(char)*1000000);

    fscanf(stdin, "%d", &ncase);

    for (i = 0; i < ncase; i++) {
        fscanf(stdin, "%s %d", s, &n);
        r = solve_case(s, n);

        printf("Case #%d: ", i + 1);
        printf("%lld\n", r);
    }

    return 0;
}
