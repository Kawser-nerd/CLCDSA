main(a){scanf("%d",&a);puts(a<60?"Bad":a<90?"Good":a>99?"Perfect":"Great");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){scanf("%d",&a);puts(a<60?"Bad":a<90?"Good":a>99?"Perfect":"Great");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);puts(a<60?"Bad":a<90?"Good":a>99?"Perfect":"Great");}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:24: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a){scanf("%d",&a);puts(a<60?"Bad":a<90?"Good":a>99?"Perfect":"Great");}
                        ^