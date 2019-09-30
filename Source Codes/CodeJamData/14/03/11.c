#include <stdio.h>

int one_click(int row, int col, int mine);

int main()
{
    int cn, cc;

    freopen("C-large.in", "r", stdin);
    freopen("c.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        int row, col, mine;
        scanf("%d%d%d", &row, &col, &mine);
        printf("Case #%d:\n", cc);

        one_click(row, col, mine);
    }

    return 0;
}

char mtr[50][50];
int one_click(int row, int col, int mine)
{
    int i,j;

    mine = row * col - mine;

    if (mine <= 0)
        goto IMPOSSIBLE;

    if (row == 1)
    {
        mtr[0][0] = 'c';
        for (i=1; i<mine; i++)
            mtr[0][i] = '.';
        while (i<col)
            mtr[0][i++] = '*';
    }
    else if (col == 1)
    {
        mtr[0][0] = 'c';
        for (i=1; i<mine; i++)
            mtr[i][0] = '.';
        while (i<row)
            mtr[i++][0] = '*';
    }
    else if (mine == 1)
    {
        for (i=0; i<row; i++)
            for (j=0; j<col; j++)
                mtr[i][j] = '*';
        mtr[0][0] = 'c';
    }
    else
    {
        for (i=2; i<=row; i++)
            for (j=2; j<=col; j++)
                if (mine <= i * j && mine >= 2 * ( i + j - 2))
                {
                    int r = i, c = j;
                    int m;
                    for (i=0; i<row; i++)
                        for (j=0; j<col; j++)
                            mtr[i][j] = '*';
                    for (i=0; i<c; i++)
                        mtr[0][i] = mtr[1][i] = '.';
                    for (i=0; i<r; i++)
                        mtr[i][0] = mtr[i][1] = '.';
                    mtr[0][0] = 'c';

                    m = mine - 2 * ( r + c - 2);
                    for (i=2; i<r; i++)
                        for (j=2; j<c; j++)
                        {
                            if (m <= 0)
                                goto PRINT;
                            mtr[i][j] = '.';
                            m--;
                        }
                    goto PRINT;
                }

        goto IMPOSSIBLE;
    }

PRINT:
    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
            putchar(mtr[i][j]);
        putchar('\n');
    }

    return 1;
IMPOSSIBLE:
    puts("Impossible");
    return 0;
}
