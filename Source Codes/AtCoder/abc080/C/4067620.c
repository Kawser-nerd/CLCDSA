#include<stdio.h>
#define M 10
#define N 100
void printB(int n)
{
    int temp;
    while(n)
    {
        temp = n&1;
        n >>= 1;
        printf("%d",temp);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    unsigned int F[N];
    int P[N][M+1];
    int temp;
    for(int i=0;i<n;i++)
    {
        F[i] = 0;
        for(int j=0;j<M;j++)
        {
            F[i] <<= 1;
            scanf("%d",&temp);
            F[i]+=temp;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<M+1;j++)
            scanf("%d",&P[i][j]);
    unsigned int times,t;
    int max = 0;
    for(int j=0;j<n;j++)
            max += P[j][F[j]&1];
    for(unsigned int i=1;i<1024;i++)
    {
        temp = 0;
        for(int j=0;j<n;j++)
        {
            t = F[j]&i;
            times = 0;
            while(t)
            {
                times += t&1;
                t >>= 1;
            }
            temp += P[j][times];
        }
        max = (max>temp)?max:temp;
    }
    printf("%d\n",max);
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:27:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&temp);
             ^
./Main.c:33:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&P[i][j]);
             ^