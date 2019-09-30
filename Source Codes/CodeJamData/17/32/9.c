#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int i,q,t,ac,aj,a,b,c,temp,d;
    scanf("%d",&t);
    for(q=1;q<=t;q++)
    {
        scanf("%d%d",&ac,&aj);
        if(ac+aj==1 || (ac+aj==2 && ac==1 && aj==1))
        {
            for(i=1;i<=ac+aj;i++)
                scanf("%d%d",&temp,&temp);
            printf("Case #%d: 2\n",q);
        }
        else
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a>c)
            {
                temp=a;
                a=c;
                c=temp;
                temp=b;
                b=d;
                d=temp;
            }
            if(c-b>=720 || d-a<=720)
                printf("Case #%d: 2\n",q);
            else
                printf("Case #%d: 4\n",q);
        }
    }
    return 0;
}
