#include<stdio.h>
int n,s=1;
int main()
{
    scanf("%d",&n);
    s=n/10*100;
    if(n%10)
    {if(n%10<7)
    s+=n%10*15;
    else
    s+=100;}
    printf("%d\n",s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^