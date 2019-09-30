#include <stdio.h>

int main() {
    int n, m, x, y;
    int friend[100][100], friends = 0, group[13], count, flag = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        friend[x][y] = 1;
        friend[y][x] = 1;
    }

    for (int bit = 0; bit < (1<<n); bit++) {
        count = 0;
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) { 
                group[count] = i;
                count++;
            }
        }

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (friend[group[i]][group[j]] != 1) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag != 1) {
            if (friends < count) {
                friends = count;
            }
        }
    }

    printf("%d\n", friends);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x, &y);
         ^