c[99];main(a){for(;a=~getchar_unlocked();)c[~a]++;for(;a<6;printf("%d%c",c[65+a++],a-5?32:10));} ./Main.c:1:1: warning: data definition has no type or storage class
 c[99];main(a){for(;a=~getchar_unlocked();)c[~a]++;for(;a<6;printf("%d%c",c[65+a++],a-5?32:10));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[99];main(a){for(;a=~getchar_unlocked();)c[~a]++;for(;a<6;printf("%d%c",c[65+a++],a-5?32:10));}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘getchar_unlocked’ [-Wimplicit-function-declaration]
 c[99];main(a){for(;a=~getchar_unlocked();)c[~a]++;for(;a<6;printf("%d%c",c[65+a++],a-5?32:10));}
                       ^
./Main.c:1:60: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 c[99];main(a){for(;a=~getchar_unlocked();)c[~a]++;for(;a<6;printf("%d%c",c[65+a++],a-5?32:10));}
                                                            ^
...