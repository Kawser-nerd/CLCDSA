#include <stdio.h>
#include <math.h>
int main(void){
    long N = 0;
    scanf("%lld", &N);
    long max = 0;
    for(int i = 1; i <= sqrt(N); i++){
        long s = i * i;
        if(s <= N){
            if(max < s){
                max = s;
            }
        }
    }
    printf("%ld\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:11: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
     scanf("%lld", &N);
           ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &N);
     ^