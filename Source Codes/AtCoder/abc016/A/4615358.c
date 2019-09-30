main(m,d){scanf("%d%d",&m,&d);puts(m%d?"NO":"YES");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(m,d){scanf("%d%d",&m,&d);puts(m%d?"NO":"YES");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(m,d){scanf("%d%d",&m,&d);puts(m%d?"NO":"YES");}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:31: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(m,d){scanf("%d%d",&m,&d);puts(m%d?"NO":"YES");}
                               ^