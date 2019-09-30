#include <stdio.h>

int main()
{
    int t, l, p;
    long long int c;
    int result, casenum;
    
    scanf("%d", &t);
    for (casenum=1; casenum<=t; casenum++)
    {
        scanf("%d%d%lld", &l, &p, &c);
        
        result = 0;
        while (l * c < p)
        {
            result++;
            c *= c;
        }
        
        printf("Case #%d: %d\n", casenum, result);
    }
    return 0;
}
