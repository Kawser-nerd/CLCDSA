#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int
main(void)
{
#define unknown 0
#define up 1
#define down 2
    int trend = unknown;
    int count = 0;
    int n;
    scanf("%d", &n);
    if (n <= 2) {
        printf("1\n");
        exit(0);
    }
    int prev;
    scanf("%d", &prev);
    int i;
    for (i = 1; i < n; ++i) {
        int current;
        scanf("%d", &current);
        switch (trend) {
        case up:
            if (prev > current) {
                count++;
                trend = unknown;
            }
            break;
        case down:
            if (prev < current) {
                count++;
                trend = unknown;
            }
            break;
        default:
            if (prev > current)
                trend = down;
            else if (prev < current)
                trend = up;
            break;
        }
        prev = current;
    }
    count++;
    printf("%d\n", count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &prev);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &current);
         ^