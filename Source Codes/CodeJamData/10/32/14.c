#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, t, l, p;
    long long c;
    int res;

    scanf("%d", &t);

    for(i = 1; i <=t; i++)
    {
        scanf("%d %d %lld", &l, &p, &c);
        res = 0;
        while(p / l > c)
        {
            c = c * c;
            res++;
        }
        if(p / l == c && p % l != 0)
            res++;

        printf("Case #%d: %d\n", i, res);
    }
}
