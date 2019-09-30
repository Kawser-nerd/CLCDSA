main(a){printf("%d\n",getchar()-64);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){printf("%d\n",getchar()-64);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a){printf("%d\n",getchar()-64);}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:23: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 main(a){printf("%d\n",getchar()-64);}
                       ^