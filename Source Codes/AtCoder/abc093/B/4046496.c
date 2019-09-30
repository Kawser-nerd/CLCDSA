#include <stdio.h>
int main()
{
    int i;
    int a,b;
    int j;
    while(scanf("%d%d%d",&a,&b,&j)!=EOF)
    {
        if(j<1 || j>100)
            break;
        if(2*j>b-a+1)
        {
            for(i=a;i<=b;i++)
            {
                printf("%d\n",i);
            }
        }
        else
        {
            for(i=a;i<=a+j-1;i++)
            {
                printf("%d\n",i);
            }
            for(i=b-j+1;i<=b;i++)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}