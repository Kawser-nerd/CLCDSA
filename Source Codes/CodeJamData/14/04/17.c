#include <stdio.h>
#include <stdlib.h>

int f(const void *a, const void *b)
{
    double p=*(double *)a;
    double q=*(double *)b;

    if (p<q)
        return 1;
    if (p>q)
        return -1;
    return 0;
}


int main()
{
    int tt,T;

    scanf("%d",&T);
    for(tt=1;tt<=T;tt++)
    {
        int n;
        scanf("%d",&n);
        double x[n];
        double y[n];

        int i,j;
        for(i=0;i<n;i++)
            scanf("%lf",x+i);
        for(i=0;i<n;i++)
            scanf("%lf",y+i);

        qsort(x,n,sizeof(double),f);
        qsort(y,n,sizeof(double),f);

        int v[1001]={0};
        int vv[1001]={0};
        int t[1001]={0};
        int k=0;
        i=j=0;
        t[0]=0;
        v[0]=0;
        while(i<n && j<n)
        {
            if (x[i]>y[j])
            {
                if (t[k]==1)
                {
                    k++;
                    t[k]=0;
                    v[k]=1;
                }
                else
                    v[k]++;
                if (k>0 && v[k]==v[k-1])
                    k-=2;
                i++;
            }
            else
            {
                if (t[k]==0)
                {
                    k++;
                    t[k]=1;
                    v[k]=1;
                }
                else
                    v[k]++;

                j++;
            }
        }

        k=0;
        i=j=n-1;
        t[0]=0;
        vv[0]=0;
        while(i>=0 && j>=0)
        {
            if (x[i]<y[j])
            {
                if (t[k]==1)
                {
                    k++;
                    t[k]=0;
                    vv[k]=1;
                }
                else
                    vv[k]++;
                if (k>0 && vv[k]==vv[k-1])
                    k-=2;
                i--;
            }
            else
            {
                if (t[k]==0)
                {
                    k++;
                    t[k]=1;
                    vv[k]=1;
                }
                else
                    vv[k]++;

                j--;
            }
        }

        printf("Case #%d: %d %d\n",tt,n-vv[0],v[0]);
    }
    return 0;
}
