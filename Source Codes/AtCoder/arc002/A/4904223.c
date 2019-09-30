main(y){scanf("%d",&y);puts(y%4>0^y%100>0^y%400>0?"NO":"YES");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(y){scanf("%d",&y);puts(y%4>0^y%100>0^y%400>0?"NO":"YES");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘y’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(y){scanf("%d",&y);puts(y%4>0^y%100>0^y%400>0?"NO":"YES");}
         ^
./Main.c:1:9: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:9: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:24: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(y){scanf("%d",&y);puts(y%4>0^y%100>0^y%400>0?"NO":"YES");}
                        ^