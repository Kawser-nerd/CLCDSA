#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    long long int a,b,c,d,e;
    scanf("%ld%ld%ld",&a,&b,&c);
    d = a*b%1000000007;
    e = d*c%1000000007;
    printf("%lld\n",e);
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld%ld%ld",&a,&b,&c);
           ^
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:6:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 4 has type ‘long long int *’ [-Wformat=]
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld",&a,&b,&c);
     ^