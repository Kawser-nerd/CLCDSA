#include <stdio.h>

int main() {
    int r, c;
    int base_map[51][51];
    int tmp_map[51][51];
    int sy, sx, gy, gx;
    char char_map[51][51];
    int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
    int count = 0;

    scanf("%d %d", &r, &c);
    scanf("%d %d", &sy, &sx);
    scanf("%d %d", &gy, &gx);
    for (int i = 0; i < r; i++) {
        scanf("%s", char_map[i]);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (char_map[i][j] == '.') {
                base_map[i][j] = 0;
            } else {
                base_map[i][j] = -1;
            }
            tmp_map[i][j] = 0;
        }
    }
    base_map[sy - 1][sx - 1] = 1;

    while (1) {
        count++;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (base_map[i][j] == 1) {
                    for (int p = 0; p < 4; p++) {
                        if (base_map[i + y[p]][j + x[p]] == 0) {
                            tmp_map[i + y[p]][j + x[p]] = 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (base_map[i][j] == 1) {
                    base_map[i][j] = -1;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tmp_map[i][j] == 1) {
                    base_map[i][j] = 1;
                    tmp_map[i][j] = 0;
                }
            }
        }

        if (base_map[gy - 1][gx - 1] == 1) {
            break;
        }
    }

    printf("%d\n", count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &r, &c);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &sy, &sx);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &gy, &gx);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", char_map[i]);
         ^