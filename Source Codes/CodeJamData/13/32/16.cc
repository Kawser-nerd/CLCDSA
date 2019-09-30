#include <cstdio>
#include <cstdlib>
#include <cstring>

int t,x,y,x0,y0,p;

int main()
{
    freopen("b-in.txt","r",stdin);
    freopen("b-out.txt","w",stdout);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&x,&y);
        x0=0;
        y0=0;
        if(x<0)p=1;
        else p=-1;
        printf("Case #%d: ",cas);
        for(int i=1;x0!=x;i++)
        {
            if(p==1)putchar('E');
            else putchar('W');
            x0+=i*p;
            p=-p;
        }
        if(y<0)p=1;
        else p=-1;
        for(int i=1;y0!=y;i++)
        {
            if(p==1)putchar('N');
            else putchar('S');
            y0+=i*p;
            p=-p;
        }
        puts("");
    }
    return 0;
}
