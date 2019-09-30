#include<stdio.h>
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    a%=(b+c);
    if(a>0&&a<=b)
    printf("Ant\n");
    else 
    printf("Bug\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^