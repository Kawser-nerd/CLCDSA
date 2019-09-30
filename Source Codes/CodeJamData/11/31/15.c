// http://code.google.com/codejam
// Task: 

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int T; // Number of tests
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        int R, C;
        scanf("%d %d", &R, &C);
        char a[R+1][C+1];
        for(int r = 0; r < R; ++r) {
            scanf("%s", a[r]);
        }

        bool possible = true;
        int cntR = 0;
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if (a[r][c] == '#') ++cntR;
            }
            if (cntR%2 == 1) possible = false;
        }
        int cntC = 0;
        for(int c = 0; c < C; ++c) {
            for(int r = 0; r < R; ++r) {
                if (a[r][c] == '#') ++cntC;
            }
            if (cntC%2 == 1) possible = false;
        }

        printf("Case #%d:\n", t);
        if (possible) {
            for(int r = 0; r < R-1; ++r) {
                for(int c = 0; c < C-1; ++c) {
                    if (a[r][c] == '#') {
                        a[r+0][c+0] = '/';
                        a[r+0][c+1] = '\\';
                        a[r+1][c+0] = '\\';
                        a[r+1][c+1] = '/';
                    }
                }
            }
            for(int r = 0; r < R; ++r) {
                printf("%s\n", a[r]);
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
