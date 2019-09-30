#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, c, sec, row, e;
    int lx, ly, rx, ry, x1, x2, y1, y2;
    char *tmp, buf[8192];
    char tbl[101][101];
    char **m;
    
    scanf("%d", &n);
    for (c = 1; c <= n; ++c) {
        sec = 0;

        for (i = 0; i < 101; ++i) {
            for (j = 0; j < 101; ++j) {
                tbl[i][j] = 0;
            }
        }
        
        lx = 101;
        ly = 101;
        rx = -1;
        ry = -1;
        
        scanf("%d", &row);
        
        for (i = 0; i < row; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            
            for (j = y1; j <= y2; ++j) {
                for (k = x1; k <= x2; ++k) {
                    tbl[j][k] = 1;
                }
            }
        
            lx = x1 < lx ? x1 : lx;
            ly = y1 < ly ? y1 : ly;
            rx = x2 > rx ? x2 : rx;
            ry = y2 > ry ? y2 : ry;
        }
                
        e = 0;
        while (!e) {
            
            m = (char **) malloc(sizeof(char *) * (ry - ly + 1));
            for (i = 0; i < (ry - ly + 1); ++i) {
                m[i] = (char *) malloc(sizeof(char) * (rx - lx + 1));
                memset(m[i], 0, (rx - lx + 1));
            }
            
            for (i = ly; i <= ry; ++i) {
                for (j = lx; j <= rx; ++j) {
                    char north = 0, west = 0;
                    if (i > 0) {
                        north = tbl[i-1][j] == 1 ? 1 : 0;
                    }
                    if (j > 0) {
                        west = tbl[i][j-1] == 1 ? 1 : 0;
                    }
                    
                    if (north == 1 && west == 1) {
                        m[i-ly][j-lx] = 1;
                    } else if (north == 0 && west == 0) {
                        m[i-ly][j-lx] = 0;                        
                    } else {
                        m[i-ly][j-lx] = tbl[i][j];                        
                    }
                }
            }
            
            e = 1;
            for (i = ly; i <= ry; ++i) {
                for (j = lx; j <= rx; ++j) {
                    tbl[i][j] = m[i-ly][j-lx];
                    if (e == 1 && tbl[i][j] == 1) {
                        e = 0;
                    }
                }
            }
            
            sec++;
        }
        
        printf("Case #%d: %d\n", c, sec);
    }
    
    return 0;
}