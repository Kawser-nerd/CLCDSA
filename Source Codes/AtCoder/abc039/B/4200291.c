main(a){scanf("%d",&a);printf("%d",(int)sqrt(sqrt(a)));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){scanf("%d",&a);printf("%d",(int)sqrt(sqrt(a)));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);printf("%d",(int)sqrt(sqrt(a)));}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:24: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);printf("%d",(int)sqrt(sqrt(a)));}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:24: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:41: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
 main(a){scanf("...