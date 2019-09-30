main(i,a)char*a;{gets(a);printf("A%cC",a[8]);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,a)char*a;{gets(a);printf("A%cC",a[8]);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 main(i,a)char*a;{gets(a);printf("A%cC",a[8]);}
                  ^
./Main.c:1:26: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(i,a)char*a;{gets(a);printf("A%cC",a[8]);}
                          ^
./Main.c:1:26: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:26: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/cctOnLwn.o: In function `main':
Main.c:(.text.startup+0xa): warning: the `gets' function is dangerous and should not be used.