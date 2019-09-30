#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int N)
{
    int used=0;
    int tmp;
    int i;
    if(N==0)
    {
        printf("INSOMNIA\n");
    }
    else
    {
        for(i=1;(used<1023);++i)
        {
            tmp = N*i;
            while(tmp>0)
            {
                used |= 1 << (tmp%10);
                tmp/=10;
            }
            if(used==1023)
            {
                printf("%d\n", N*i);
                break;
            }
        }
    }
}

int main()
{
    int t, T;
    int N;
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d",&N);

        printf("Case #%d: ", t);
        solve(N);
    }

    return 0;
}
