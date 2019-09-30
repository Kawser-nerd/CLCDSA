#include<stdio.h>
int n,srx,sry,lhy,i;
int main()
{
    scanf("%d%d%d",&srx,&sry,&n);
    for(i=1;i<=n;++i)
    {scanf("%d",&lhy);
    if(lhy<srx)
    printf("%d\n",srx-lhy);
    else if(lhy>sry)
    printf("-1\n");
    else
    printf("0\n");}
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&srx,&sry,&n);
     ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     {scanf("%d",&lhy);
      ^