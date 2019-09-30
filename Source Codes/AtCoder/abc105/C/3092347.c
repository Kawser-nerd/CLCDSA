main(d){~scanf("%d",&d)|d&&main(-(d>>1))*putchar(48|d&1);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(d){~scanf("%d",&d)|d&&main(-(d>>1))*putchar(48|d&1);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:10: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(d){~scanf("%d",&d)|d&&main(-(d>>1))*putchar(48|d&1);}
          ^
./Main.c:1:10: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:10: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:42: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
 main(d){~scanf("%d",&d)|d&&main(-(d>>1))*putchar(48|d&1);}
                                          ^