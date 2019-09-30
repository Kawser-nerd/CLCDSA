#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        long int town, days, minzoku, **limit, **startgoal;
        long int i, j, now;

        scanf("%ld %ld %ld", &town, &days, &minzoku);
        limit = calloc(sizeof(long int *), days);
        for (i = 0; i < days; i++) {
                limit[i] = calloc(sizeof(long int), 2);
                scanf("%ld %ld", &limit[i][0], &limit[i][1]);
        }
        startgoal = calloc(sizeof(long int *), minzoku);
        for (i = 0; i < minzoku; i++) {
                startgoal[i] = calloc(sizeof(long int *), 2);
                scanf("%ld %ld", &startgoal[i][0], &startgoal[i][1]);
        }

        for (i = 0; i < minzoku; i++) {
                now = startgoal[i][0];
                for (j = 0; j < days; j++) {
                        if (now >= limit[j][0] && now <= limit[j][1]) {
                                if (now > startgoal[i][1]) {
                                        now = limit[j][0];
                                        now = startgoal[i][1] >= limit[j][0] ? startgoal[i][1] : limit[j][0];                                } else if (now < startgoal[i][1]) {
                                        now = startgoal[i][1] <= limit[j][1] ? startgoal[i][1] : limit[j][1];
                                }                                if (now == startgoal[i][1]) {
                                        printf("%ld\n", j + 1);
                                        break;
                                }
                        }
                }
        }
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld %ld %ld", &town, &days, &minzoku);
         ^
./Main.c:14:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%ld %ld", &limit[i][0], &limit[i][1]);
                 ^
./Main.c:19:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%ld %ld", &startgoal[i][0], &startgoal[i][1]);
                 ^