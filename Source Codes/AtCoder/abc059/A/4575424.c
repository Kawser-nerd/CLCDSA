main(a){for(;a>33||putchar((a=getchar())<0?10:a-32)>10;a=getchar());} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){for(;a>33||putchar((a=getchar())<0?10:a-32)>10;a=getchar());}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 main(a){for(;a>33||putchar((a=getchar())<0?10:a-32)>10;a=getchar());}
                    ^
./Main.c:1:31: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a){for(;a>33||putchar((a=getchar())<0?10:a-32)>10;a=getchar());}
                               ^