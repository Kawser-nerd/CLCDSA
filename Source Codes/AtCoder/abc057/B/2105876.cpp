#include <stdio.h>
#include <math.h>
int main()
{
    int N,M,i,j,k,l;
    scanf("%d %d",&N,&M);
    long long int a[N][2],b[M][2],c[N],n,d;

    for(i=0;i<N;i++)
    {
        scanf("%lld",&a[i][0]);
        scanf("%lld",&a[i][1]);
    }

    for(j=0;j<M;j++)
    {
        scanf("%lld",&b[j][0]);
        scanf("%lld",&b[j][1]);
    }
    for(k=0;k<N;k++)
    {
        n=pow(10,17);
        for(l=0;l<M;l++)
        {
            d=fabs(a[k][0]-b[l][0])+fabs(a[k][1]-b[l][1]);
            if(d<n)
            {
              c[k]=l+1;
              n=d;
            }
        }
        printf("%lld\n",c[k]);
    }
    return 0;
}