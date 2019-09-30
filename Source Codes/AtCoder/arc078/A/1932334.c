#include<stdio.h>
long long a[300000];
long long fab(long long a)
{
    if(a>=0)
        return a;
    else return -a;
}
int main(void)
{
    long long N,m=0,n,p,q,l,s=0;
    scanf("%lld",&N);
    for(n=0;n<N;n++)
    {
        scanf("%lld",&a[n]);
        s=s+a[n];
    }
    p=fab(a[0]-s/2);
    for(n=0;n<N-1;n++)
    {
        m=m+a[n];
        if(fab(m-s/2)<=p) {l=m;p=fab(m-s/2);}
    }
    q=l-(s-l);
    printf("%lld",fab(q));
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&N);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[n]);
         ^