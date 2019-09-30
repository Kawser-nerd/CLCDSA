main(x){gets(&x);printf("%d\n",x%482%53%8);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(x){gets(&x);printf("%d\n",x%482%53%8);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 main(x){gets(&x);printf("%d\n",x%482%53%8);}
         ^
./Main.c:1:18: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(x){gets(&x);printf("%d\n",x%482%53%8);}
                  ^
./Main.c:1:18: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:18: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/tmp/ccHyFJk6.o: In function `main':
Main.c:(.text.startup+0x10): warning: the `gets' function is dangerous and should not be used.