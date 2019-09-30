#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

int main()
{
    int iCase, T;
    long long P, Q, a, b, t;
    int ans,flag,gen;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%lld/%lld",&P,&Q);
        if (P>Q)
        {
            printf("Case #%d: impossible\n",iCase);
            continue;
        }
        a = Q;
        b = P;
        while ( a % b != 0)
        {
            t = b;
            b = a % b;
            a = t;
        }

        Q = Q / b;
        P = P / b;

        ans = 0;
        gen = 0;
        flag = 1;
        while (Q>1)
        {
            if ( Q % 2 !=0)
            {
                flag = 0;
                break;
            }
            if ( P < Q)
                ans++;
            Q = Q/2;
            gen++;
        }
        if (flag==1 && gen<=40)
            printf("Case #%d: %d\n",iCase,ans);
        else
            printf("Case #%d: impossible\n",iCase);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
