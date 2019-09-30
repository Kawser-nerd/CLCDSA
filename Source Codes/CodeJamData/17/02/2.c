#include <stdio.h>
#include <string.h>

int ti, tn, i, j;
char a[20];

int
main()
{
    fscanf(stdin, "%d", &tn);
    for (ti = 1; ti <= tn; ++ti) {
        fprintf(stdout, "Case #%d: ", ti);
        fscanf(stdin, "%s", a);
        for (i = (int)strlen(a) - 1; i >= 1; --i)
            if (a[i] < a[i - 1]) {
                a[i - 1] -= 1;
                for (j = i; a[j]; ++j)
                    a[j] = '9';
            }
        for (i = 0; a[i] == '0'; ++i);
        fprintf(stdout, "%s\n", a + i);
    }

    return 0;
}
