#include <stdio.h>
#include <stdlib.h>



int fja(const void *a, const void *b)
{
    int p,q;
    p=*(long long *)a;
    q=*(long long *)b;

    if (p<q)
        return -1;
    return p>q;
}

int main()
{
    int T,t;

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        long long A;
        int N;
        int min=100;
        long long m[100];
        int i,j;
        scanf("%lld %d",&A,&N);
        for(i=0;i<N;i++)
            scanf("%lld",m+i);

        if (A==1)
        {
            min=i;
        }
        else
        {
            qsort(m,N,sizeof(long long),fja);
            int q=0;
            for(i=0;i<N;i++)
            {
                if (A>m[i])
                {
                    A+=m[i];
                    continue;
                }
                if (N-i+q<min)
                    min=N-i+q;
                while(A<=m[i])
                {
                    q++;
                    A=2*A-1;
                }
                A+=m[i];
            }
            if (q<min)
                min=q;
        }

        printf("Case #%d: %d\n",t,min);


    }

    return 0;
}
