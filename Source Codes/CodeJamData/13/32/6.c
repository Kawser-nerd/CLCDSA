#include<stdio.h>
typedef long long ll;
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);


    int t,cs;
    int x,y;
    int i,j,k,t1,t2,t3,cx,cy,d1,d2;

    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        scanf("%d %d",&x,&y);
        if(x>0)
        t1='E';
        else
        {
            t1='W';
            x=-x;
        }
        if(y>0)
        t2='N';
        else
        {
            t2='S';
            y=-y;
        }
        cx=cy=0;
        for(i=1;;i++)
        {
            if((cx+i)<=x)
            {
                printf("%c",t1);
                cx+=i;
            }
            else
            if((cy+i)<=y)
            {
                printf("%c",t2);
                cy+=i;
            }
            else
            break;
        }
        d1=x-cx;
        d2=y-cy;
        if(t1=='E')
        {
            for(i=0;i<d1;i++)printf("WE");
        }
        else
        {
            for(i=0;i<d1;i++)printf("EW");
        }
        if(t2=='N')
        {
            for(i=0;i<d2;i++)printf("SN");
        }
        else
        {
            for(i=0;i<d2;i++)printf("NS");
        }
        printf("\n");
    }
    return 0;
}
