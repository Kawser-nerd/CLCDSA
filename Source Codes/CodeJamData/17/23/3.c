#include <stdio.h>
#include <string.h>
#define INF 1000000000000
#define MIN(X,Y) ((X)<(Y) ? (X) : (Y))

typedef long long LL;
LL T,n,q,e[110],s[110],d[110][110],r[110][110],cnt[110];
double f[110][110];

int main(void)
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    scanf("%lld",&T);
    LL t0;
    for(t0=1;t0<=T;t0++)
    {
        scanf("%lld%lld",&n,&q);
        LL i,j,k;
        for(i=1;i<=n;i++)
            scanf("%lld%lld",&e[i],&s[i]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%lld",&d[i][j]);
                if(i==j) d[i][j]=0;
                else if(d[i][j]==-1) d[i][j]=INF;
            }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(d[i][j]<=e[i])
                    r[i][++cnt[i]]=j;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                f[i][j] = i==j ? 0 : INF;
        for(i=1;i<=n;i++)
            for(j=1;j<=cnt[i];j++)
                f[i][r[i][j]]=(double)d[i][r[i][j]]/s[i];
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    f[i][j]=MIN(f[i][j],f[i][k]+f[k][j]);
        printf("Case #%lld: ",t0);
        LL u,v;
        for(i=1;i<=q;i++)
        {
            scanf("%lld%lld",&u,&v);
            printf("%.6f",f[u][v]);
            printf("%c",i==q ? '\n' : ' ');
        }
    }
    return 0;
}
