#include <stdio.h>
long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");} ./Main.c:2:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
               ^
./Main.c: In function ‘main’:
./Main.c:2:49: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
                                                 ^
./Main.c:2:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
                      ^