#include <stdio.h>
#include <stdlib.h>
int count=0;

int judge(long long int data,int n,int a,int b,int c)
{
    if(data>n)
        return 0;
    if(a==1&&b==1&&c==1)
    {
        count++;
    }
    judge(data*10+3,n,1,b,c);
    judge(data*10+5,n,a,1,c);
    judge(data*10+7,n,a,b,1);

    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    judge(0,t,0,0,0);
    printf("%d\n",count);
    return 0;


} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&t);
     ^