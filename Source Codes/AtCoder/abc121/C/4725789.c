#include <stdio.h>
#include <stdlib.h>
typedef struct{
    long price;
    long stock;
} shop;
long long MIN(long long a, long long b){
    return a<b?a:b;
}
int compare(const void *a,const void *b){
    shop tmp1= *(shop*)a;
    shop tmp2= *(shop*)b;
    long  x=tmp1.price;
    long y=tmp2.price;
    return x<y?-1:1;
}
int main()
{   int n,m;
    scanf("%d%d",&n,&m);
    shop a[n];
    for(int i=0;i<n;i++){
        scanf("%ld%ld",&a[i].price,&a[i].stock);
    }
    qsort(a,n,sizeof(shop),compare);
    
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=MIN(m,a[i].stock)*a[i].price;
        m-=MIN(m,a[i].stock);
    }
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld%ld",&a[i].price,&a[i].stock);
         ^