i;main(a){for(;~(a=getchar());)++i%2&&putchar(a);} ./Main.c:1:1: warning: data definition has no type or storage class
 i;main(a){for(;~(a=getchar());)++i%2&&putchar(a);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i;main(a){for(;~(a=getchar());)++i%2&&putchar(a);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 i;main(a){for(;~(a=getchar());)++i%2&&putchar(a);}
                    ^
./Main.c:1:39: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 i;main(a){for(;~(a=getchar());)++i%2&&putchar(a);}
                                       ^