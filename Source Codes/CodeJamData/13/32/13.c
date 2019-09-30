#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABS(x) ((x)>0?(x):(-x))

/* for small case */
char* solve_case(int x, int y)
{
    char r[1024] = { 0, };
    int p = 0;
    int i;

    for (i = 0; i < ABS(x); i++) {
        r[p] = (x > 0) ? 'W' : 'E';
        r[p + 1] = (x > 0) ? 'E' : 'W';
        p += 2;
    }

    for (i = 0; i < ABS(y); i++) {
        r[p] = (y > 0) ? 'S' : 'N';
        r[p + 1] = (y > 0) ? 'N' : 'S';
        p += 2;
    }

    return strdup(r);
}

int main()
{
    int ncase, i, x, y;
    char *s;

    fscanf(stdin, "%d", &ncase);

    for (i = 0; i < ncase; i++) {
        fscanf(stdin, "%d %d", &x, &y);
        s = solve_case(x, y);
        printf("Case #%d: ", i + 1);
        printf("%s\n", s);
        free(s);
    }

    return 0;
}
