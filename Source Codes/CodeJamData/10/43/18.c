#include <stdio.h>
#include <string.h>

#ifndef max
    #define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
    #define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef abs
    #define abs(a) (((a) >= 0) ? (a) : -(a))
#endif

int grid[2][101][101];

int checkGrid(int k)
{
    int i, j;
    for (i = 0; i < 101; i++)
    {
        for (j = 0; j < 101; j++)
        {
            if (grid[k][i][j] == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}

void clearGrid(int k)
{
    int i, j;
    for (i = 0; i < 101; i++)
    {
        for (j = 0; j < 101; j++)
        {
            grid[k][i][j] = 0;
        }
    }
}

void solve(FILE *fin, FILE *fout, int caseNum)
{
    memset(grid, 0, sizeof(grid));
    int r;
    int i, j, k;
    int x1, y1, x2, y2;
    int check, nk;
    int count;
    fscanf(fin, "%d", &r);
    for (i = 0; i < r; i++)
    {
        fscanf(fin, "%d %d %d %d", &x1, &y1, &x2, &y2);
        for (j = x1; j <= x2; j++)
        {
            for (k = y1; k <= y2; k++)
            {
                grid[0][j][k] = 1;
            }
        }
    }
    k = 0;
    check = checkGrid(k);
    //printf("%d\n", check);
    count = 0;
    while (check == 1)
    {
        if (k == 0)
            nk = 1;
        else
            nk = 0;
            
        clearGrid(nk);
        
        for (i = 0; i < 101; i++)
        {
            for (j = 0; j < 101; j++)
            {
                if (grid[k][i][j] == 1)
                {
                    if ((grid[k][i-1][j] == 0) && (grid[k][i][j-1] == 0))
                    {
                        grid[nk][i][j] = 0;
                    }
                    else
                    {
                        grid[nk][i][j] = 1;
                    }
                }
                else
                {
                    if ((grid[k][i-1][j] == 1) && (grid[k][i][j-1] ==1))
                    {
                        grid[nk][i][j] = 1;
                    }
                    else
                    {
                        grid[nk][i][j] = 0;
                    }
                }
            }
        }
        k = nk;
        check = checkGrid(k);
        //printf("%d\n", check);
        count++;
    }
    printf("%d\n", count);
    fprintf(fout, "Case #%d: %d\n", caseNum, count);
}

int main(int argc, char **argv)
{
    FILE *fin;
    FILE *fout;
    char fileIn[] = "C-";
    char fileOut[] = "C-";
    char suffixIn[] = ".in";
    char suffixOut[] = ".out";
    int i, t;
    strcat(fileIn, *++argv);
    strcat(fileOut, *argv);
    strcat(fileIn, suffixIn);
    strcat(fileOut, suffixOut);
    fin = fopen(fileIn, "r");
    fout = fopen(fileOut, "w");
    fscanf(fin, "%d", &t);
    for (i = 1; i <= t; i++)
    {
        solve(fin, fout, i);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
