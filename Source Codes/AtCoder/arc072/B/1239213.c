#include <stdio.h>
long long a,b;
main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
 ^
./Main.c: In function ‘main’:
./Main.c:3:35: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
                                   ^
./Main.c:3:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
        ^