#include<stdio.h>
int n;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i=1;i<=n;++i)
    printf("%d\n",1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^