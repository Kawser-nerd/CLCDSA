#include <stdio.h>
#include <string.h>

void mine(int case_n, int R, int C, int M) {
    int possible;
    int r, c, swap_rc;
    int m;
    char map[50][50];
    memset((void*)map, '.', sizeof(map));

    // Swap row and column for simple logic.
    if (R >= C) {
        swap_rc = 0;
    } else {
        int tmp = R;
        R = C;
        C = tmp;
        swap_rc = 1;
    }

    // Check number of mines.
    if (M == 0) {
        possible = 1;
        goto PRINT_RESULT;
    }else if ((R * C) - 1 == M) {
        memset((void*)map, '*', sizeof(map));
        possible = 1;
        goto PRINT_RESULT;
    }
    if (R * C <= M) {
        possible = 0;
        fprintf(stderr, "Mine is overflowing.\n");
        goto PRINT_RESULT;
    }

    if (C == 1) {
        /*
         * c***
         *
         * cn**
         *
         * c.n*
         */
        for (m = M, r = R - 1; m > 0; m--) {
            map[r--][0] = '*';
        }
        possible = 1;
        goto PRINT_RESULT;
    } else if(C == 2) {
        if (M % 2 == 1) {
            /*
             * cnN
             * .n*
             */
            possible = 0;
            fprintf(stderr, "Must be odd mines.\n");
            goto PRINT_RESULT;
        } else if (R - (M / 2) <= 1) {
            /*
             * c**
             * N**
             */
            possible = 0;
            fprintf(stderr, "Too small space.\n");
            goto PRINT_RESULT;
        }
        /*
         * cn*
         * .n*
         */
        m = M;
        r = R - 1;
        while (m){
            map[r][0] = '*';
            map[r][1] = '*';
            m -= 2;
            r--;
        }
        possible = 1;
        goto PRINT_RESULT;
    } else if (C >= 3) {
        if (C == 3 && R == 3) {
            if(M == 1) {
                /*
                 * c..
                 * .nn
                 * .n*
                 */
                map[2][2] = '*';
                possible = 1;
                goto PRINT_RESULT;
            } else if (M == 3) {
                /*
                 * c..
                 * nnn
                 * ***
                 */
                map[2][0] = '*';
                map[2][1] = '*';
                map[2][2] = '*';
                possible = 1;
                goto PRINT_RESULT;
            } else if (M == 5) {
                /*
                 * cn*
                 * nn*
                 * ***
                 */
                map[2][0] = '*';
                map[2][1] = '*';
                map[2][2] = '*';
                map[1][2] = '*';
                map[0][2] = '*';
                possible = 1;
                goto PRINT_RESULT;
            }
            /*
             * c..
             * nnn
             * N**
             */
            possible = 0;
            goto PRINT_RESULT;
        }
        r = R - 1;
        c = C - 1;
        m = M;
        while(m) {
            map[r][c] = '*';
            m--;
            r--;
            if (r < 2) {
                r = R - 1;
                c--;
                if (c < 2)
                    break;
            }
        }
        int odd_mine = 0;
        if (m % 2 == 1) {
            map[2][2] = '.';
            m++;
            odd_mine = 1;
        }
        r = R - 1;
        while(m && r >= (2 + odd_mine)) {
            map[r][0] = '*';
            map[r][1] = '*';
            r--;
            m -= 2;
        }

        c = C - 1;
        while(m && c >= (2 + odd_mine)) {
            map[0][c] = '*';
            map[1][c] = '*';
            c--;
            m -= 2;
        }

        if (m) {
            possible = 0;
            goto PRINT_RESULT;
        } else {
            possible = 1;
            goto PRINT_RESULT;
        }
    }

PRINT_RESULT:
    printf("Case #%d:\n", case_n);
    if(possible) {
        map[0][0] = 'c';
        if (swap_rc) {
            for(c = 0; c < C; c++) {
                for (r = 0; r < R; r++) {
                    putc(map[r][c], stdout);
                }
                putc('\n', stdout);
            }
        } else {
            for(r = 0; r < R; r++) {
                for (c = 0; c < C; c++) {
                    putc(map[r][c], stdout);
                }
                putc('\n', stdout);
            }
        }
    } else {
        printf("Impossible\n");
    }
}

int main() {
    FILE* fp = fopen("input.txt", "r");
    int T, t;

    fscanf(fp, "%d", &T);

    for (t = 0; t < T; t++) {
        int R, C, M;
        fscanf(fp, "%d %d %d", &R, &C, &M);
        mine(t + 1, R, C, M);
    }
    return 0;
}
