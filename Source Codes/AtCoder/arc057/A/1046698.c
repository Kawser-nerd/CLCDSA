#include <stdio.h>
int main (void){
    unsigned long long int now;
    unsigned long long int zouka;
    scanf("%lld %lld",&now,&zouka);
    unsigned long long int day=0;
    if(zouka==0){
        day=2000000000000-now;
    }else{
        while(now<2000000000000){
            now+=1+(now*zouka);
            day++;
            //printf("%llu\n",now);
        }
    }
    
    printf("%llu",day);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld",&now,&zouka);
     ^