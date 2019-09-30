#include <stdio.h>
#include <string.h>

int T,n,r,o,y,g,b,v;
char col[1010];

int main(void)
{
    freopen("stable.in","r",stdin);
    freopen("stable.out","w",stdout);
    scanf("%d",&T);
    int t0;
    for(t0=1;t0<=T;t0++)
    {
        scanf("%d%d%d%d%d%d%d",&n,&r,&o,&y,&g,&b,&v);
        if(r>n/2 || b>n/2 || y>n/2)
        {
            printf("Case #%d: IMPOSSIBLE\n",t0);
            continue;
        }
        memset(col,0,sizeof(col));
        int i;
        for(i=1;i<=n;i+=2)
        {
            if(!r) break;
            col[i]='R';
            r--;
        }
        int f = b>y ? 1 : 0;
        for(i=n;i>=1;i--)
        {
            if(col[i]) continue;
            if((f && b) || !y)
            {
                col[i]='B';
                b--;
            }
            else
            {
                col[i]='Y';
                y--;
            }
            f^=1;
        }
        printf("Case #%d: ",t0);
        for(i=1;i<=n;i++)
            printf("%c",col[i]);
        putchar('\n');

        if(col[1]==col[n]) printf("error x\n");
        for(i=1;i<n;i++)
            if(col[i]==col[i+1]) printf("error\n");
        if(r) printf("error r\n");
        else if(b) printf("error b\n");
        else if(y) printf("error y\n");
    }
    return 0;
}
