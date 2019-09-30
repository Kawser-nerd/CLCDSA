#include <stdio.h>

#define MAX (1 << 10)

int solve(int rounds, int jumpOffset, int * miss, int * cost, int missed)
{
    int result, result2, i;
    
    if (rounds == 1)
    {
        if (miss[0] > missed && miss[1] > missed)
            return 0;
        else
            return cost[1];
    }
    
    result = cost[1] + solve(rounds-1, 2*jumpOffset, miss, cost+jumpOffset, missed) + solve(rounds-1, 2*jumpOffset+1, miss+(1<<rounds-1), cost+jumpOffset+1, missed);
    
    for (i=0; i<1<<rounds; i++)
        if (miss[i] == missed)
            return result;
    
    result2 = solve(rounds-1, 2*jumpOffset, miss, cost+jumpOffset, missed+1) + solve(rounds-1, 2*jumpOffset+1, miss+(1<<rounds-1), cost+jumpOffset+1, missed+1);
    
    return result < result2 ? result : result2;
}

int main()
{
    int t, p, miss[MAX], cost[MAX];
    int i, j;
    int casenum;
    
    scanf("%d", &t);
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d", &p);
        for (i=0; i<1<<p; i++)
            scanf("%d", &miss[i]);
        for (j=p-1; j>=0; j--)
            for (i=0; i<1<<j; i++)
                scanf("%d", &cost[(1<<j)+i]);
        
        printf("Case #%d: %d\n", casenum, solve(p, 1, miss, cost, 0));
    }
    return 0;
}
