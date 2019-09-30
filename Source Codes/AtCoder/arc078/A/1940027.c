#include<stdio.h>
long long int jdz(long long int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    int n,i,x;
    long long int a[200005],mini;
    scanf("%d",&n);
    scanf("%lld",&a[0]);
    for(i=1;i<n;i++){
        scanf("%lld",&a[i]);
        a[i]=a[i-1]+a[i];
    }
    mini=jdz(a[n-1]-2*a[0]);
    for(i=1;i<n-1;i++){
        if(jdz(a[n-1]-2*a[i])<mini){
        mini =jdz(a[n-1]-2*a[i]);
        }
    }
    printf("%lld",mini);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a[0]);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^