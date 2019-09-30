#include<stdio.h>
int main()
{
    int n;
   while(~scanf("%d",&n))
    {
          int a,b;
        if(n>=10&&n<=99)

    {
        a=n%10;
    b=n/10;
    if(a==9||b==9)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    }
    
    }
    return 0;
}