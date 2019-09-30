#include<stdio.h>
int main()
{
    int a,b,c,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    if(k%2==0)
        printf("%d\n",a-b);
    else
        printf("%d\n",b-a);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&k);
     ^