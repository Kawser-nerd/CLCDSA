#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, ac, aj;
    int c[101], d[101], j[101], k[101];
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &ac, &aj);

        for (int ii = 0; ii < ac; ii++)
            scanf("%d %d", &c[ii], &d[ii]);
        for (int ii = 0; ii < aj; ii++)
            scanf("%d %d", &j[ii], &k[ii]);

        int result = 2;

        if (ac == 2 &&
            (d[1] - c[0] > 720 && c[1] - d[0] < 720 ||
             d[0] - c[1] > 720 && c[0] - d[1] < 720))
            result = 4;
        if (aj == 2 &&
            (k[1] - j[0] > 720 && j[1] - k[0] < 720 ||
              k[0] - j[1] > 720 && j[0] - k[1] < 720))
            result = 4;

        printf("Case #%d: %d\n", i + 1, result);
    }

    return 0;
}
