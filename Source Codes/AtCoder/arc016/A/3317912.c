main(){puts(getchar(getchar(getchar()))%2?"2":"1");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){puts(getchar(getchar(getchar()))%2?"2":"1");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(){puts(getchar(getchar(getchar()))%2?"2":"1");}
        ^
./Main.c:1:13: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(){puts(getchar(getchar(getchar()))%2?"2":"1");}
             ^