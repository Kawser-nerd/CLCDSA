#include <stdio.h>
int caculate_pro(int shop[10],int per[100][10],int pro[100][11],int size)
{
    int i,j,result=0;
    int temp[100]={0};
    for (i=0;i<10;i++)
    {
        if (shop[i]==1){
            for(j=0;j<size;j++)             //j????????
            {
                temp[j]+=per[j][i];         //??j??????????????
            }
        }
    }
    for (i=0;i<size;i++)
    {
        result+=pro[i][temp[i]];             //????
    }
    return result;
}
int  main()
{
    int n,result,fold,i,i1,j,max,index;
    int per[100][10]={0},pro[100][11]={0};
    int shop[10];
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        for (j=0;j<10;j++)
        {
            scanf("%d",&per[i][j]);
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<11;j++)
        {
            scanf("%d",&pro[i][j]);
        }
    }
    for (i=1;i<1024;i++)
    {
        i1=i;
        for (j=0;j<10;j++)
        {
            shop[j]=i1%2;
            i1=i1/2;
        }
        if (i==1){
            max=caculate_pro(shop,per,pro,n);
            index=1;
        }
        else if (max<caculate_pro(shop,per,pro,n))
        {
            max=caculate_pro(shop,per,pro,n);
            index=i;
        }
    }
    printf("%d\n",max);
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:31:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&per[i][j]);
             ^
./Main.c:38:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&pro[i][j]);
             ^