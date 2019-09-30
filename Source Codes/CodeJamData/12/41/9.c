#include <stdio.h>
#include <math.h>

int main()
{
    int T,tt;
    scanf("%d",&T);
    for(tt=1;tt<=T;tt++)
    {
        int n;
        int d[10001],l[10001];
        int c[10001]={0};
        int D;
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
            scanf("%d %d",d+i,l+i);
        scanf("%d",d+i);
        l[n]=0;c[n]=-1;

        c[0]=d[0];
        int j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if (c[i]<d[j]-d[i])
                    break;
                int temp=d[j]-d[i];
                if (temp>l[j])
                    temp=l[j];
                if (temp>c[j])
                    c[j]=temp;
            }
        }


        printf("Case #%d: ",tt);
        if (c[n]>=0) printf("YES\n"); else printf("NO\n");
    }

    return 0;




}
