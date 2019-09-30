#include<stdio.h>
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(a<0)
    a=-a;
    if(b<0)
    b=-b;
    if(a>b)
    printf("Bug\n");
    else if(a==b)
    printf("Draw\n");
    else 
    printf("Ant\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^