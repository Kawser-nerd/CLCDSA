main(a,b)char*b;{scanf("%s%d",b,&a);a--;printf("%c%c\n",b[a/5],b[a%5]);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b)char*b;{scanf("%s%d",b,&a);a--;printf("%c%c\n",b[a/5],b[a%5]);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b)char*b;{scanf("%s%d",b,&a);a--;printf("%c%c\n",b[a/5],b[a%5]);}
                  ^
./Main.c:1:18: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:18: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:41: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a,b)char*b;{scanf("%s%d",b,&a);a--;printf("%c%c\n",b[a/5],b[a%5]);}
                                         ^
./Main.c:1:41: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:41: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’