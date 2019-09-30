#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int a[4];
    for(i=0;i<4;i++)
        scanf("%1d",&a[i]);
    if(a[0]+a[1]+a[2]+a[3]==7)
    {printf("%d+%d+%d+%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]+a[1]+a[2]-a[3]==7)
    {printf("%d+%d+%d-%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]+a[1]-a[2]+a[3]==7)
    {printf("%d+%d-%d+%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]+a[1]-a[2]-a[3]==7)
    {printf("%d+%d-%d-%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]-a[1]+a[2]+a[3]==7)
    {printf("%d-%d+%d+%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]-a[1]+a[2]-a[3]==7)
    {printf("%d-%d+%d-%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]-a[1]-a[2]+a[3]==7)
    {printf("%d-%d-%d+%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    if(a[0]-a[1]-a[2]-a[3]==7)
    {printf("%d-%d-%d-%d=7",a[0],a[1],a[2],a[3]);
    return 0;
    }
    return 0;
}