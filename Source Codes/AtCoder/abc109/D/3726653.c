#include <stdio.h>

typedef struct {
    int y, x;
    int yy, xx;
} _;

_ arr[500 * 500 + 5];

int main()
{
    int h, w;
    int mp[505][505];
    int n = 0;

    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            scanf("%d", &mp[i][j]);
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i != h && j == w) {
                if (mp[i][j] % 2) {
                    arr[n] = (_){i, j, i + 1, j};
                    n++;
                    
                    mp[i + 1][j] += 1;
                }
            } else if (j < w) {
                if (mp[i][j] % 2) {
                    arr[n] = (_){i, j, i, j + 1};
                    n++;

                    mp[i][j + 1] += 1;
                }
            }
        }
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d\n", arr[i].y, arr[i].x, arr[i].yy, arr[i].xx);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &w);
     ^
./Main.c:19:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &mp[i][j]);
             ^