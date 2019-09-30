#include <stdio.h>
#include <string.h>
#include <assert.h>

long long doTest(void)
{
    static char used[256];
    static char num[64];
    int base;
    int currDig;
    int i;
    long long res;
    char usedZero;
    
    memset(used, 0, sizeof used);
    gets(num);
    base = 0;
    
    for(i=0; num[i]; i++)
    {
        if(!used[num[i]])
        {
            used[num[i]] = -1;
            base++;
        }
    }
    
    if(base == 1)
    {
        base = 2;
    }
    
    res = 0;
    currDig = 1;
    usedZero = 0;
    
    for(i=0; num[i]; i++)
    {
        if(used[num[i]] == -1)
        {
            if(currDig == 2 && !usedZero)
            {
                used[num[i]] = 0;
                usedZero = 1;
            }
            else
            {
                used[num[i]] = currDig++;
            }
        }
        res = res*base + used[num[i]];
    }
    
    return res;
}

int main(void)
{
    int T, test;
    
    scanf("%d\n", &T);
    for(test=1; test<=T; ++test)
    {
        printf("Case #%d: %I64d\n", test, doTest());
    }
    return 0;
}
