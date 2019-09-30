main(a,b){scanf("%d%d",&a,&b);puts(a<9&&b<9?"Yay!":":(");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){scanf("%d%d",&a,&b);puts(a<9&&b<9?"Yay!":":(");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);puts(a<9&&b<9?"Yay!":":(");}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:31: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);puts(a<9&&b<9?"Yay!":":(");}
                               ^