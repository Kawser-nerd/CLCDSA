main(a,s)char*s;{for(;~scanf("%s",s);)a++>2&&puts(s)*puts(s);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,s)char*s;{for(;~scanf("%s",s);)a++>2&&puts(s)*puts(s);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:24: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,s)char*s;{for(;~scanf("%s",s);)a++>2&&puts(s)*puts(s);}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:24: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:46: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a,s)char*s;{for(;~scanf("%s",s);)a++>2&&puts(s)*puts(s);}
                                              ^