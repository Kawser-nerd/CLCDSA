#include <stdio.h>

#define MAX 51

int main()
{
    int t, k;
    int grid[MAX][MAX];
    int i, j, c1, c2, isOK;
    int casenum;
    
    scanf("%d", &t);
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d", &k);
        for (i=0; i<k; i++)
            for (j=0; j<=i; j++)
                scanf("%d", &grid[i-j][j]);
        for (i=1; i<k; i++)
            for (j=i; j<k; j++)
                scanf("%d", &grid[k-1+i-j][j]);
        
        for (c1=0; c1<k-1; c1++)
        {
            isOK = 1;
            for (i=0; isOK && i<k-c1; i++)
                for (j=0; isOK && j<i; j++)
                    if (grid[c1+i][j] != grid[c1+j][i])
                        isOK = 0;
            if (isOK)
                break;
            if (c1==0)
                continue;
            isOK = 1;
            for (i=0; isOK && i<k-c1; i++)
                for (j=0; isOK && j<i; j++)
                    if (grid[i][c1+j] != grid[j][c1+i])
                        isOK = 0;
            if (isOK)
                break;
        }
        
        for (c2=0; c2<k-1; c2++)
        {
            isOK = 1;
            for (i=0; isOK && i<k-c2; i++)
                for (j=0; isOK && j<i; j++)
                    if (grid[k-1-c2-i][j] != grid[k-1-c2-j][i])
                        isOK = 0;
            if (isOK)
                break;
            if (c2==0)
                continue;
            isOK = 1;
            for (i=0; isOK && i<k-c2; i++)
                for (j=0; isOK && j<i; j++)
                    if (grid[k-1-i][c2+j] != grid[k-1-j][c2+i])
                        isOK = 0;
            if (isOK)
                break;
        }
        
        c1 += c2;
        
        printf("Case #%d: %d\n", casenum, c1*c1 + 2*c1*k);
    }
    return 0;
}
