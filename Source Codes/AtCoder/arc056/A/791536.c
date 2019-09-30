#include <stdio.h>
int main(void){
    // Here your code !
    unsigned long long int a,b,k,l;
    unsigned long long int modThreshold;
    unsigned long long int price,mod;
    scanf("%llu %llu %llu %llu",&a,&b,&k,&l);
    modThreshold = b/a;
    price = b * (k/l);
    mod = k%l;
    if(mod > modThreshold){
        price += b;
    }else{
        price += a*mod;
    }
    printf("%llu",price);
    
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%llu %llu %llu %llu",&a,&b,&k,&l);
     ^