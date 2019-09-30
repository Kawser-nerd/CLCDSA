#include <stdio.h>
#include <stdlib.h>

char m[55][55];

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, R, C, i, j, t;

    scanf("%d ", &T);

    for (t=1; t<=T; t++) {
        scanf("%d %d ", &R, &C);

        for (i=1; i<=R; i++) {
            for (j=1; j<=C; j++) {
                scanf("%c", &m[i][j]);
            }
            scanf("\n");
        }

        for (i=1; i<=R; i++) {
            for (j=1; j<=C; j++) {
                if ( m[i][j] == '#' ) {
                    m[i][j] = '/';
                    if ( i != R && m[i+1][j] == '#' ) m[i+1][j] = '\\';
                    else break;
                    if ( j != C && m[i][j+1] == '#' ) m[i][j+1] = '\\';
                    else break;
                    if ( i != R && j != C && m[i+1][j+1] == '#' ) m[i+1][j+1] = '/';
                    else break;
                }
            }
            if ( j <= C ) break;
        }

        printf("Case #%d:\n", t);
        if ( i <= R ) {
            printf("Impossible\n");
        }
        else {
            for (i=1; i<=R; i++) {
                for (j=1; j<=C; j++) {
                    printf("%c", m[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}

