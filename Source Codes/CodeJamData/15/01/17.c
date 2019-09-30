#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count=0,ans=0;

void solve()
{
    count=0,ans=0;
    int n,i,m,t;
    scanf("%d",&n);

    for(i=0; i<=n; i++)
    {
        scanf("%1d",&m);
        if(count < i)
        {
            ans+=i-count;
            count+=i-count;
        }
        count+=m;
       // printf("x%d\n",count);
    }
    printf("%d\n",ans);
}

int main()
{
    int q,i;
    scanf("%d",&q);
    for(i=1; i<=q; i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
