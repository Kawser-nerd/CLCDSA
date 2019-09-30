#include<stdio.h>
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    if((b-a)%2==0)
    puts("Alice");
    else
    puts("Borys");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^