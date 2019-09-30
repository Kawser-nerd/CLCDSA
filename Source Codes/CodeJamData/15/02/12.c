#include <stdio.h>

int a[1010];

void solve()
{
    int n,i,j,max=0,min=99999,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] > max)
            max=a[i];
    }
    for(i=1;i<=max;i++)
    {
        t=0;
        for(j=1;j<=n;j++)
            t+=(a[j]-1)/i;
        t+=i;

        if(t < min)
            min=t;
    }
    printf("%d\n",min);
}

int main()
{
    int q,i;
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
