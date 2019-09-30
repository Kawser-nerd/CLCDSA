#include <stdio.h>

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int r, c, m, j, k;
        char s[50][51] = {{0}};
        
        scanf("%d %d %d", &r, &c, &m);
        
        printf("Case #%d: \n", i + 1);
        
        if (m == 0) {
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    if (j == 0 && k == 0) {
                        s[j][k] = 'c';
                    } else {
                        s[j][k] = '.';
                    }
                }
            }
        } else if (m == r * c - 1) {
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    if (j == 0 && k == 0) {
                        s[j][k] = 'c';
                    } else {
                        s[j][k] = '*';
                    }
                }
            }
        } else if (r == 1) {
            for (j = 0; j < c; j++) {
                if (j < m) {
                    s[0][j] = '*';
                } else {
                    s[0][j] = '.';
                }
            }
            
            s[0][c - 1] = 'c';
        } else if (c == 1) {
            for (j = 0; j < r; j++) {
                if (j < m) {
                    s[j][0] = '*';
                } else {
                    s[j][0] = '.';
                }
            }
            
            s[r - 1][0] = 'c';
        } else if (r == 2) {
            if (m % 2 == 1 || m == r * c - 2) {
                puts("Impossible");
                
                continue;
            }
            
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    if (k < m / 2) {
                        s[j][k] = '*';
                    } else {
                        s[j][k] = '.';
                    }
                }
            }
            
            s[0][c - 1] = 'c';
        } else if (c == 2) {
            if (m % 2 == 1 || m == r * c - 2) {
                puts("Impossible");
                
                continue;
            }
            
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    if (j < m / 2) {
                        s[j][k] = '*';
                    } else {
                        s[j][k] = '.';
                    }
                }
            }
            
            s[r - 1][0] = 'c';
        } else if (r * c - m == 2 || r * c - m == 3 || r * c - m == 5 || r * c - m == 7) {
            puts("Impossible");
            
            continue;
        } else {
            for (j = 0; j < r; j++) {
                for (k = 0; k < c; k++) {
                    s[j][k] = '*';
                }
            }
            
            m = r * c - m;
            
            if (r * 2 + c * 2 - 4 <= m) {
                for (j = 0; j < r; j++) {
                    for (k = 0; k < c; k++) {
                        if (j < 2 || k < 2) s[j][k] = '.';
                    }
                }
                
                m -= r * 2 + c * 2 - 4;
                
                for (j = 2; j < r; j++) {
                    for (k = 2; k < c; k++) {
                        if (m > 0) {
                            s[j][k] = '.';
                            m--;
                        }
                    }
                }
            } else if (m == 4 || m == 6) {
                for (j = 0; j < m / 2; j++) s[0][j] = s[1][j] = '.';
            } else {
                int x, y;
                
                for (j = 3; j < r; j++) {
                    for (k = 3; k < c; k++) {
                        if (j * 2 + k * 2 - 4 == m / 2 * 2) {
                            x = j;
                            y = k;
                            
                            break;
                        }
                    }
                }
                
                for (j = 0; j < r; j++) {
                    for (k = 0; k < c; k++) {
                        if ((j <= x && k < 2) || (k <= y && j < 2)) s[j][k] = '.';
                    }
                }
                
                if (m % 2 == 1) s[2][2] = '.';
            }
            
            s[0][0] = 'c';
        }
        
        for (j = 0; j < r; j++) printf("%s\n", s[j]);
    }
    
    return 0;
}
