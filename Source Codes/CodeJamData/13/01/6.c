#include <stdio.h>

char table[5][5];

int main () {
    
    int t, c, i, j, xWins, oWins, xCount, oCount, dot;
    scanf("%d", &t);
    
    for (c = 1 ; t-- ; c++) {
        for (i = 0 ; i < 4 ; i++)
            scanf("%s", table[i]);
        dot = xWins = oWins = 0;
        xCount = oCount = 0;
        for (i = 0 ; i < 4 ; i++) {
            if (table[i][i] == 'X')
                xCount++;
            else if (table[i][i] == 'O')
                oCount++;
            else if (table[i][i] == 'T') {
                xCount++;
                oCount++;
            } else
                dot = 1;
        }
        if (xCount == 4)
            xWins = 1;
        if (oCount == 4)
            oWins = 1;
        xCount = oCount = 0;
        for (i = 0 ; i < 4 ; i++) {
            if (table[i][3-i] == 'X')
                xCount++;
            else if (table[i][3-i] == 'O')
                oCount++;
            else if (table[i][3-i] == 'T') {
                xCount++;
                oCount++;
            } else
                dot = 1;
        }
        if (xCount == 4)
            xWins = 1;
        if (oCount == 4)
            oWins = 1;
        for (i = 0 ; i < 4 ; i++) {
            xCount = oCount = 0;
            for (j = 0 ; j < 4 ; j++)
                if (table[i][j] == 'X')
                    xCount++;
                else if (table[i][j] == 'O')
                    oCount++;
                else if (table[i][j] == 'T') {
                    xCount++;
                    oCount++;
                } else
                    dot = 1;
            if (xCount == 4)
                xWins = 1;
            if (oCount == 4)
                oWins = 1;
            xCount = oCount = 0;
            for (j = 0 ; j < 4 ; j++)
                if (table[j][i] == 'X')
                    xCount++;
                else if (table[j][i] == 'O')
                    oCount++;
                else if (table[j][i] == 'T') {
                    xCount++;
                    oCount++;
                } else
                    dot = 1;
            if (xCount == 4)
                xWins = 1;
            if (oCount == 4)
                oWins = 1;
        }
        if (xWins)
            printf("Case #%d: X won\n", c);
        else if (oWins)
            printf("Case #%d: O won\n", c);
        else if (dot)
            printf("Case #%d: Game has not completed\n", c);
        else
            printf("Case #%d: Draw\n", c);
    }
    
    return 0;
    
}
