#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long int i,j;
int cmpr(const void*a,const void*b){
    return *(long long int*)a-*(long long int*)b;
}
int main(void){
    long long int n,m;
    long long int a[100000][2];
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)scanf("%lld %lld",&a[i][0],&a[i][1]);
    qsort(a,n,sizeof(a[0]),cmpr);
    long long int sum=0,cnt=0;
   // for(int i=0;i<n;i++)printf("%d %d\n",a[i][0],a[i][1]);
    for(i=0;i<n;i++){
        for(j=0;j<a[i][1];j++){
            sum+=a[i][0];
            cnt++;
            if(cnt>=m) break;
        }
      if(cnt>=m) break;
    }
    printf("%lld",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&n,&m);
     ^
./Main.c:12:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++)scanf("%lld %lld",&a[i][0],&a[i][1]);
                     ^