main(a){puts(getchar()&1?"ABC":"chokudai");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){puts(getchar()&1?"ABC":"chokudai");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a){puts(getchar()&1?"ABC":"chokudai");}
         ^
./Main.c:1:14: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a){puts(getchar()&1?"ABC":"chokudai");}
              ^