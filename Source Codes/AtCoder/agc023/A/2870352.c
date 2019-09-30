#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int sort(const void * a, const void * b){
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}

int main(void){
    int n;
    scanf("%d",&n);
    long long a[n],sum[n+1],ans=0,tmp=0;
    sum[0]=0;
    for (int i=0; i<n; i++){
        scanf("%lld",&a[i]);
        sum[i+1]=sum[i]+a[i];
    }
    qsort (sum,n+1,sizeof(long long),sort); 
    for (int i=0; i<n+1; i++){
        if(sum[i]==sum[i+1]){
            tmp++;
        } else {
            tmp++;
            ans+=(tmp-1)*tmp/2;
            tmp=0;
        }
    }
    ans+=(tmp-1)*tmp/2;
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:21:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^