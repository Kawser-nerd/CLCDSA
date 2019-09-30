#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

void solve()
{
    int x,r,c,n;
    scanf("%d %d %d",&x,&r,&c);
    if(x>=7) n=1;
    else if(x>r && x>c) n=1;
    else if((r*c)%x!=0) n=1;
    else if((x+1)/2 > min(r,c)) n=1;
    else if(x<4) n=2;
    else if(x==4)
    {
        if(min(r,c)>2) n=2;
        else n=1;
    }
    else if(x==5)
    {
        if(min(r,c)==3 && max(r,c)==5)
            n=1;
        else n=2;
    }
    else if(x==6)
    {
        if(min(r,c) > 3) n=2;
        else n=1;
    }

    if(n==1)
        printf("RICHARD\n");
    else printf("GABRIEL\n");
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
