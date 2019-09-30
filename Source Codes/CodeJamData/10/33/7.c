#include <stdio.h>
#include <string.h>

char map[513][513];
char used[513][513];
int row, col;
int res[513];

int get_val(char ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    return ch - 'A' + 10;
}
int main()
{
    int tc, cn;
    int i, j, k, l, x;
    int len, temp, cnt;
    int fl;
    char cur;
    char buf[1000];

    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d%d", &row, &col);
        for (i = 0; i < row; i++) {
            scanf("%s", buf);
            k = 0;
            for (j = 0; j < col; j += 4, k++) {
                temp = get_val(buf[k]);
                for (l = 3, x = 0; l >= 0; l--, x++) {
                    if (temp & (1 << l))
                        map[i][j+x] = 1;
                    else
                        map[i][j+x] = 0;
                }
            }
        }

        memset(res, 0, sizeof(res));
        memset(used, 0, sizeof(used));

        cnt = 0;
        for (len = col; len >= 1; len--) {
            for (i = 0; i < row; i++) {
                if (i+len-1 >= row)
                    break;
                for (j = 0; j < col; j++) {
                    if (j+len-1 >= col)
                        break;
                    fl = 1;
                    for (k = 0; k < len && fl; k++) {
                        for (l = 0; l < len; l++) {
                            if (used[i+k][j+l]) {
                                fl = 0;
                                break;
                            }
                            cur = map[i+k][j+l];
                            if (l > 0 && cur == map[i+k][j+l-1]) {
                                fl = 0;
                                break;
                            }
                            if (k > 0 && cur == map[i+k-1][j+l]) {
                                fl = 0;
                                break;
                            }
                        }
                        if (!fl)
                            break;
                    }

                    if (fl) {
                        res[len]++;
                        for (k = 0; k < len; k++) {
                            for (l = 0; l < len; l++) {
                                used[i+k][j+l] = 1;
                            }
                        }
                    }
                }
            }
            if (res[len] > 0)
                cnt++;
        }

        printf("Case #%d: %d\n", cn, cnt);
        for (i = 512; i >= 1; i--) {
            if (res[i] > 0) {
                printf("%d %d\n", i, res[i]);
            }
        }
    }
    return 0;
}
