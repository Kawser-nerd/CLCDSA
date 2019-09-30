#include <math.h>
#include <stdio.h>
#include <string.h>

#define DIR_N (16)
#define DIR_BUF (3 + 1)
#define DIS_N (13)

int main(void)
{
    /* ????? */
    int deg, dis;

    /* ?????*/
    int        deg_list[DIR_N];
    char       dir[DIR_BUF];
    const char dir_list[DIR_N][DIR_BUF] = {
        "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"
    };

    /* ????? */
    int       w;
    const int dis_list[DIS_N] = { 15, 93, 201, 327, 477, 645, 831, 1029, 1245, 1467, 1707, 1959, 12001 };
    // l = [round((n + 0.05) * 60) for n in [0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6]]; l.append(12001); print(l)

    /* ???? */
    scanf("%d %d\n", &deg, &dis);

    /* ????????????? */
    for (int i = 0; i < DIR_N; i++)
    {
        deg_list[i] = 1125 * (2 * i + 1);
    }

    /* ???? */
    strncpy(dir, dir_list[0], DIR_BUF);

    for (int i = 0; i < DIR_N; i++)
    {
        if (deg * 10 < deg_list[i])
        {
            strncpy(dir, dir_list[i], DIR_BUF);
            break;
        }
    }

    /* ???? */
    w = 12;

    for (int i = 0; i < DIS_N; i++)
    {
        if (dis < dis_list[i])
        {
            w = i;
            break;
        }
    }

    /* ???? */
    if (w == 0)
    {
        strncpy(dir, "C", DIR_BUF);
    }

    printf("%s %d\n", dir, w);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n", &deg, &dis);
     ^