#include<stdio.h>
int main()
{
    int x,y,z,a,b;
    scanf("%d",&x);
    scanf("%d",&a);
    scanf("%d",&b);
    if(x>a&&x>b)
    {
        y=x-a;
        z=x-b;
    }
    else if(x>a&&x<b)
    {
        y=x-a;
        z=b-x;
    }
    else if(x<a&&x>b)
    {
        y=a-x;
        z=x-b;
    }
    else
    {
        y=a-x;
        z=b-x;
    }
    if(y<z)
    {
        printf("A");
    }
    else
    {
        printf("B");
    }
    return 0;
}