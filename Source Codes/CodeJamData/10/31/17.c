#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wire[2000][2];

int main()
{
    int i, j, k, t, n;
    int res;

    scanf("%d", &t);

    for(i = 1; i <= t ; i++)
    {
        scanf("%d", &n);

        for(j = 0; j < n; j++)
        {
            scanf("%d %d", &wire[j][0], &wire[j][1]);
        }

        res = 0;
        for(j = 0; j < n; j++)
        {
            for(k = j+1; k < n ; k++)
            {
                if(wire[j][0] > wire[k][0] && wire[j][1] < wire[k][1])
                    res++;
                if(wire[j][0] < wire[k][0] && wire[j][1] > wire[k][1])
                    res++;
            }
        }

        printf("Case #%d: %d\n", i, res);
    }
}
