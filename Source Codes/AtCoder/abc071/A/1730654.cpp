#include<stdio.h>
int main()
{
    int x,a,b,m,n;
    while(~scanf("%d%d%d",&x,&a,&b))
    {
        if(x-a>0)
        {
            m=x-a;
            }
       else
       {
           m=-(x-a);
       }
    if(x-b>0)
       {
           n=x-b;
       }
       else
    {
        n=-(x-b);
       }
    if(m>n)
       {
           printf("B\n");
       }
       else
{
    printf("A\n");
}
    }

}