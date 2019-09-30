#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, m, n;
    int i,j,k;
    int nc;
    int a,b;
    double p[200000];
    double cp[200000];
    double correctp;
    double expectkey;
    double key;

    scanf("%d", &t);

    for(nc = 1; nc <= t; nc++)
    {
        scanf("%d %d", &a, &b);

        for(i = 0; i < a; i++)
            scanf("%lf", &p[i]);
            
        correctp = 1.0;
        expectkey = 2 + b;

        for(i = 0; i < a;i++)
        {
            if(i == 0)
                cp[i] = p[i];
            else
                cp[i] = cp[i-1] * p[i];

        }
        for(i = 0; i < a;i++)
        {
            key = cp[a-i-1] * (b-a+1) + (1-cp[a-i-1]) * ((b-a+1) + (b+1)) + (i*2);
            if(key < expectkey)
            {
                expectkey = key;
                //printf("i:%d, key:%lf\n", i, expectkey);
            }

        }
        printf("Case #%d: %06lf\n",nc,expectkey);
    }
}
