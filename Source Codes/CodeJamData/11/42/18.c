#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char diff[20][20];
int R, C, D, T, t;

int calc(int r, int c, int size) {
    double centerx = r-1 + size/2.0, centery = c-1 + size/2.0;
    double ansx, ansy;
    int i, j;

    ansx = 0;
    ansy = 0;
   
    for (i=r; i<=r+size-1; i++) {
        for (j=c; j<=c+size-1; j++) {
            if ( ( i == r || i == r + size - 1 ) && ( j == c || j == c + size - 1 ) ) {
                continue;
            }

            ansx += (i-0.5-centerx)*(D+(double)diff[i][j]);
            ansy += (j-0.5-centery)*(D+(double)diff[i][j]);
        }
    }

    if ( fabs(ansx) < 1e-10 && fabs(ansy) < 1e-10 ) {
        return 1;
    }

    return 0;
}


int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j, k, K, found;

    scanf("%d\n", &T);

    for (t=1; t<=T; t++) {
        found = 0;

        scanf("%d %d %d\n", &R, &C, &D);

        for (i=1; i<=R; i++) {
            for (j=C; j>=1; j--) {
                scanf("%c", &diff[i][j]);
                diff[i][j]-='0';
            }
            scanf("\n");
        }

        K = (R < C ? R : C);

        for (k=K; k>=3; k--) {
            for (i=1; i<=R-k+1; i++) {
                for (j=1; j<=C-k+1; j++) {
                    if ( calc(i, j, k) == 1 ) {
                        found = 1; break;
                    }
                }
                if ( found ) break;
            }
            if ( found ) break;
        }

        printf("Case #%d: ", t);
        if ( found ) {
            printf("%d\n", k);
        }
        else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}

