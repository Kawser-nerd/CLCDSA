#include <stdio.h>
#include <string.h>
#define INF 1e14
#define MIN(X,Y) ((X)<(Y) ? (X) : (Y))

int T,n,d,k[1010],s[1010];

int main(void)
{
    freopen("cruise.in","r",stdin);
    freopen("cruise.out","w",stdout);
    scanf("%d",&T);
    int t0;
    for(t0=1;t0<=T;t0++)
    {
        scanf("%d%d",&d,&n);
        int i;
        for(i=1;i<=n;i++)
            scanf("%d%d",&k[i],&s[i]);
        double ans=INF;
        for(i=1;i<=n;i++)
            ans=MIN(ans,(double)d*s[i]/(d-k[i]));
        printf("Case #%d: %.6f\n",t0,ans);
    }
    return 0;
}
