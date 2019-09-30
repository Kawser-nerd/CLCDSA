#include<stdio.h>
int srx,sry,lhy;
int main()
{
    scanf("%d%d%d",&srx,&sry,&lhy);
    if(srx==sry&&srx==lhy)
    {printf("%d\n",srx);
    return 0;}
    if(srx==sry)
    printf("%d\n",lhy);
    else if(srx==lhy)
    printf("%d\n",sry);
    else if(sry==lhy)
    printf("%d\n",srx);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&srx,&sry,&lhy);
     ^