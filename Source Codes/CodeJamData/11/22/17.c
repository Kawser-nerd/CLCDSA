#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findtime(int *p,int *v, int p1, int p2, int d)
{
    int sv=0;
    int i;
    for(i=p1;i<=p2;i++)
    {
        sv+=v[i];
    }
    int dp = p[p2]-p[p1];
    int out;
    out = (sv-1)*d-dp;
    if (out>0)
        return out;
    else
        return 0;
}

int main()
{
    int cases,casenum=1;
    scanf("%d",&cases);
    while(cases--)
    {
        int c, d;
        scanf("%d %d",&c,&d);
        int *p;
        int *v;
        p = malloc(sizeof(int)* c);
        v = malloc(sizeof(int)* c);
        int i,j;
        int tmax=0;
        int vmax=0;
        for(i=0;i<c;i++)
        {
            scanf("%d %d",&p[i],&v[i]);
        }

        for(i=0;i<c-1;i++)
        {
            for(j=i+1;j<c;j++)
            {
                int t=findtime(p,v,i,j,d);
                if (t>tmax)
                    tmax=t;
            }
        }
        for(i=0;i<c;i++)
        {
            if(v[i]>vmax)
            {
                vmax=v[i];
            }

        }
        if ((vmax-1)*d > tmax)
            tmax=(vmax-1)*d;
        printf("Case #%d: %.1f\n",casenum++,tmax/2.0);
    }
    return 0;
}
