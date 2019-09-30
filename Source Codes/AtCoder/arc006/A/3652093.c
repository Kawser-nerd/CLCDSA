#include<stdio.h>
int srx[7],mzy,sry,lhy,zjq,i,j,lgx;
int main()
{
    for(i=1;i<=6;i++)
    scanf("%d",&srx[i]);
    scanf("%d",&sry);
    for(i=1;i<=6;i++)
    {lgx=0;
    scanf("%d",&mzy);
    for(j=1;j<=6;j++)
    {if(mzy==srx[j])
    {lhy++;
    srx[j]=-1;
    lgx=1;
    break;}}
    if(lgx==1)
    continue;
    if(mzy==sry)
    zjq=1;}
    if(lhy==6)
    printf("1\n");
    else if(lhy==5&&zjq==1)
    printf("2\n");
    else if(lhy==5)
    printf("3\n");
    else if(lhy==4)
    printf("4\n");
    else if(lhy==3)
    printf("5\n");
    else
    printf("0\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&srx[i]);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&sry);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&mzy);
     ^