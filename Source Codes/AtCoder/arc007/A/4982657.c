main(a,b){for(gets(&a);b=getchar()+1;)b-a-1?putchar(b-1):0;} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){for(gets(&a);b=getchar()+1;)b-a-1?putchar(b-1):0;}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 main(a,b){for(gets(&a);b=getchar()+1;)b-a-1?putchar(b-1):0;}
               ^
./Main.c:1:26: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a,b){for(gets(&a);b=getchar()+1;)b-a-1?putchar(b-1):0;}
                          ^
./Main.c:1:45: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 main(a,b){for(gets(&a);b=getchar()+1;)b-a-1?putchar(b-1):0;}
                                             ^
/tmp/ccRPToGc.o: In function `main':
Main.c:(.text.startup+0x10): warning: the `gets' function is dangerous and should not be used.