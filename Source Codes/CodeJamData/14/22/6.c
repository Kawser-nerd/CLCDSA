#include <stdio.h>

long long ff(int a, int b, int k, int bit)
{
    if (bit==0)
        return 1;

    long long ukupno=0;

    int q[2][2][2]={0};

    int i,j,m;
    int qa,qb,qk;
    qa=(a&bit)?1:0;
    qb=(b&bit)?1:0;
    qk=(k&bit)?1:0;

    for(i=0;i<=qa;i++)
        for(j=0;j<=qb;j++)
            if ((i&j)<=qk)
                q[i==qa && (a&bit-1)!=bit-1][j==qb && (b&bit-1)!=bit-1][(i&j)==qk && (k&bit-1)!=bit-1]++;

    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(m=0;m<2;m++)
                if (q[i][j][m])
                    ukupno+=q[i][j][m]*ff(i?(a&bit-1):bit-1,j?(b&bit-1):bit-1,m?(k&bit-1):bit-1,bit>>1);

    return ukupno;
}


int test(int a, int b, int k)
{
    int i,j;
    int ukupno=0;
    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            ukupno+=((i&j)<k);
    return ukupno;
}


int main()
{
    int t,T;

    scanf("%d",&T);

    for(t=1;t<=T;t++)
    {
        int a,b,k;
        scanf("%d %d %d",&a,&b,&k);
        printf("Case #%d: %lld\n",t,ff(a-1,b-1,k-1,1<<30));
    }
    return 0;
}
