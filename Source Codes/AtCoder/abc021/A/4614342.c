main(a){scanf("%d",&a);for(printf("%d\n",a);a--;)puts("1");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){scanf("%d",&a);for(printf("%d\n",a);a--;)puts("1");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);for(printf("%d\n",a);a--;)puts("1");}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:28: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);for(printf("%d\n",a);a--;)puts("1");}
                            ^
./Main.c:1:28: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:28: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:50: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
...