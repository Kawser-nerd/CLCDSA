#include <stdio.h>
main(){long long x;scanf("%lld",&x);printf("%lld\n",x/11*2+(x%11+5)/6);} ./Main.c:2:1: warning: return type defaults to �int� [-Wimplicit-int]
 main(){long long x;scanf("%lld",&x);printf("%lld\n",x/11*2+(x%11+5)/6);}
 ^
./Main.c: In function �main�:
./Main.c:2:20: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
 main(){long long x;scanf("%lld",&x);printf("%lld\n",x/11*2+(x%11+5)/6);}
                    ^