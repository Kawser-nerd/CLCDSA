#include <stdio.h>

int n, m, lawn[101][101];

int can_do (int i, int j, int lim) {
    
    int a, lo_logre;
    
    if (lawn[i][j] >= lim)
        return 1;
    
    lo_logre = 1;
    for (a = 0 ; a < n && lo_logre ; a++)
        if (lawn[a][j] >= lim)
            lo_logre = 0;
    if (lo_logre)
        return lo_logre;
    lo_logre = 1;
    for (a = 0 ; a < m && lo_logre ; a++)
        if (lawn[i][a] >= lim)
            lo_logre = 0;
    
    return lo_logre;
    
}

int main () {
    
    int t, c, i, j, i_can, lim;
    scanf("%d", &t);
    
    for (c = 1 ; t-- ; c++) {
        scanf("%d%d", &n, &m);
        for (i = 0 ; i < n ; i++)
            for (j = 0 ; j < m ; j++)
                scanf("%d", &lawn[i][j]);
        i_can = 1;
        for (lim = 100 ; lim >= 0 && i_can ; lim--)
            for (i = 0 ; i < n && i_can ; i++)
                for (j = 0 ; j < m && i_can ; j++)
                    i_can = can_do(i, j, lim);
        printf("Case #%d: %s\n", c, i_can ? "YES" : "NO");
    }
    
    return 0;
    
}
