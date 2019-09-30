main(a,b){for(;b=(a=getchar())<33&&b^(a=getchar())?0:a;);puts(a<0?"YES":"NO");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){for(;b=(a=getchar())<33&&b^(a=getchar())?0:a;);puts(a<0?"YES":"NO");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:21: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a,b){for(;b=(a=getchar())<33&&b^(a=getchar())?0:a;);puts(a<0?"YES":"NO");}
                     ^
./Main.c:1:58: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a,b){for(;b=(a=getchar())<33&&b^(a=getchar())?0:a;);puts(a<0?"YES":"NO");}
                                                          ^