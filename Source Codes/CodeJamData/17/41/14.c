#include <stdio.h>
#include <string.h>
#define MIN(X,Y) ((X)<(Y) ? (X) : (Y))

int T,n,p,cnt[10];

int main(void)
{
    freopen("chocolate.in","r",stdin);
    freopen("chocolate.out","w",stdout);
    scanf("%d",&T);
    int t0;
    for(t0=1;t0<=T;t0++)
    {
        printf("Case #%d: ",t0);
        scanf("%d%d",&n,&p);
        memset(cnt,0,sizeof(cnt));
        int i,g;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&g);
            cnt[g%p]++;
        }
        int ans,t;
        if(p==2)
            ans=cnt[0]+(cnt[1]+1)/2;
        else if(p==3)
        {
            t=MIN(cnt[1],cnt[2]);
            ans=cnt[0]+t;
            cnt[1]-=t;  cnt[2]-=t;
            t=cnt[1]/3+cnt[2]/3;
            ans+=t;
            if(cnt[1]%3 || cnt[2]%3) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
