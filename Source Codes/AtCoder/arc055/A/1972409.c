i;main(n){scanf("%d",&n);for(;~n--;)putchar(i++?~n?48:55:49);} ./Main.c:1:1: warning: data definition has no type or storage class
 i;main(n){scanf("%d",&n);for(;~n--;)putchar(i++?~n?48:55:49);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i;main(n){scanf("%d",&n);for(;~n--;)putchar(i++?~n?48:55:49);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i;main(n){scanf("%d",&n);for(;~n--;)putchar(i++?~n?48:55:49);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:37: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 i;main(n){scanf("%d",&n);for(;~n--;)putchar(i++?~n?48:55:49);}
                                     ^