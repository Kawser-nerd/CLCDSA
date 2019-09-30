#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(void){
    long long int n,m,a[50],b[50],c[50],d[50],i,j,dist,mindist,minnum;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
    }
    for(j=0;j<m;j++){
        scanf("%lld%lld",&c[j],&d[j]);
    }
    for(i=0;i<n;i++){
        mindist=LLONG_MAX;
        for(j=0;j<m;j++){
            dist=llabs(c[j]-a[i])+llabs(d[j]-b[i]);
            if(dist<mindist){
                mindist=dist;
                minnum=j+1;
            }
        }
        printf("%lld\n",minnum);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&m);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&a[i],&b[i]);
         ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&c[j],&d[j]);
         ^