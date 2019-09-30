main(a){scanf("%s",&a);printf("%d\n",a-96+a/256&31);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){scanf("%s",&a);printf("%d\n",a-96+a/256&31);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a){scanf("%s",&a);printf("%d\n",a-96+a/256&31);}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
 main(a){scanf("%s",&a);printf("%d\n",a-96+a/256&31);}
               ^
./Main.c:1:24: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a){scanf("%s",&a);printf("%d\n",a-96+a/256&31);}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:24:...