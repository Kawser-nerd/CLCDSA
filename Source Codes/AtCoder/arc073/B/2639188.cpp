#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;

struct good
{
    int w,v;
}g[110];

bool cmp(good a,good b)
{
    return a.v > b.v;
}
good A[110],B[110],C[110],D[110];

LL swa[110],swb[110],swc[110],swd[110];//??????
LL sva[110],svb[110],svc[110],svd[110];//??????

int main(void)
{
    int n,w,i,j,k,l;
    int a,b,c,d;
    while(scanf("%d%d",&n,&w)==2)
    {
        a = b = c = d = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&g[i].w,&g[i].v);
            if(g[i].w == g[1].w)
                A[++a] = g[i];
            if(g[i].w == g[1].w + 1)
                B[++b] = g[i];
            if(g[i].w == g[1].w + 2)
                C[++c] = g[i];
            if(g[i].w == g[1].w + 3)
                D[++d] = g[i];
        }
        sort(A+1,A+a+1,cmp);
        sort(B+1,B+b+1,cmp);
        sort(C+1,C+c+1,cmp);
        sort(D+1,D+d+1,cmp);
        swa[0] = swb[0] = swc[0] = swd[0] = 0;
        sva[0] = svb[0] = svc[0] = svd[0] = 0;
        for(i=1;i<=a;i++)
        {
            swa[i] = swa[i-1] + A[i].w;
            sva[i] = sva[i-1] + A[i].v;
        }
        for(i=1;i<=b;i++)
        {
            swb[i] = swb[i-1] + B[i].w;
            svb[i] = svb[i-1] + B[i].v;
        }
        for(i=1;i<=c;i++)
        {
            swc[i] = swc[i-1] + C[i].w;
            svc[i] = svc[i-1] + C[i].v;
        }
        for(i=1;i<=d;i++)
        {
            swd[i] = swd[i-1] + D[i].w;
            svd[i] = svd[i-1] + D[i].v;
        }
        int sumv = 0;
        int ans = 0;
        for(i=0;i<=a;i++)
        {
            for(j=0;j<=b;j++)
            {
                for(k=0;k<=c;k++)
                {
                    for(l=0;l<=d;l++)
                    {
                        LL sum = swa[i] + swb[j] + swc[k] + swd[l];
                        if(sum <= (LL)w)
                        {
                            ans = max((LL)ans,sva[i]+svb[j]+svc[k]+svd[l]);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}