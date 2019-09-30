#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    long long n;
    long long ans=10,tmp;
    scanf("%lld",&n);
    for (long long i=1; i<100000; i++){
        if (n%i==0){
            long long j=n/i,i2=i,count=0;
            tmp=0;
            while (j>0){
                j/=10;
                count++;
            }
            while (i2>0){
                i2/=10;
                tmp++;
            }
            if (count>tmp){
                tmp=count;
            }
        }
        if (ans>tmp){
        ans=tmp;
        }
    }
    printf ("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^