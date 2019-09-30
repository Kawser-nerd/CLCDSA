main(a){for(;a=getchar(),a^10;putchar(a));puts("s");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){for(;a=getchar(),a^10;putchar(a));puts("s");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:16: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a){for(;a=getchar(),a^10;putchar(a));puts("s");}
                ^
./Main.c:1:31: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 main(a){for(;a=getchar(),a^10;putchar(a));puts("s");}
                               ^
./Main.c:1:43: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a){for(;a=getchar(),a^10;putchar(a));puts("s");}
                                           ^