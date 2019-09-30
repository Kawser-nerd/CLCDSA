#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int sort (const void * a, const void * b){
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}

int main(void){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long a[n],b[n],count[100005],anscount=0;
    for (int i=0; i<100005; i++){
        count[i]=0;
    }
    for (long long i=0; i<n; i++){
        scanf("%lld%lld",&a[i],&b[i]);
        count[a[i]]+=b[i];
    }
    qsort (a,n,sizeof(long long),sort);
    
    for (long long i=0; i<n; i++){
        if (i==0 || a[i]!=a[i-1]){
            anscount+=count[a[i]];
        }
        if (anscount>=k){
            printf ("%lld\n",a[i]);
            break;
        }
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&n,&k);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&a[i],&b[i]);
         ^