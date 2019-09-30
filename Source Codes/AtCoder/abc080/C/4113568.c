#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct open
{
    long period[10];
};
struct profits
{
    long momney[11];
};
int cmp(const void *a,const void *b)
{
    return *(int*)b-*(int*)a;
}
long ownpow(long x,long n)
{
    long i,result=1;
    for(i=1;i<=n;i++)
    {
        result*=x;
    }
    return result;
}
int main()
{
    long profit[1024],i,j,k,time[100],result,t,n;
    long p[1024][10];
    struct open shop[100];
    struct profits gain[100];
    for(n=1;n<1024;n++)
    {
        k=n;
        for(i=0;i<10;i++)
        {
            t=pow(2,9-i);
            if(k/t==1)
                p[n-1][i]=1;
            else(p[n-1][i]=0);
            k%=t;
        }
    }
    /*for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }*/
    //profit[0]=-2555555;
    scanf("%ld",&k);
    for(i=0;i<k;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%ld",&shop[i].period[j]);
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<11;j++)
        {
            scanf("%ld",&gain[i].momney[j]);
        }
    }
    for(n=1;n<1024;n++)
    {
        for(i=0;i<k;i++)
        {
            time[i]=0;
        }
        for(i=0;i<10;i++)// ??
        {
          for(j=0;j<k;j++)//??
          {
              if(p[n-1][i]==1&&shop[j].period[i]==1)
                time[j]++;
          }
        }
        result=0;
        for(i=0;i<k;i++)
        {
            result+=gain[i].momney[time[i]];
        }
        profit[n-1]=result;
    }
    qsort(profit,1023,sizeof(profit[0]),cmp);
    printf("%ld\n",profit[0]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:15: warning: implicit declaration of function ‘pow’ [-Wimplicit-function-declaration]
             t=pow(2,9-i);
               ^
./Main.c:36:15: warning: incompatible implicit declaration of built-in function ‘pow’
./Main.c:36:15: note: include ‘<math.h>’ or provide a declaration of ‘pow’
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&k);
     ^
./Main.c:57:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld",&shop[i].period[j]);
             ^
./Main.c:64:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%ld",&gain[i].momney[j]);
             ^