main(a,b,c,d){scanf("%d%d%d%d",&a,&b,&c,&d);printf("%d",a*b<c*d?c*d:a*b);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b,c,d){scanf("%d%d%d%d",&a,&b,&c,&d);printf("%d",a*b<c*d?c*d:a*b);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b,c,d){scanf("%d%d%d%d",&a,&b,&c,&d);printf("%d",a*b<c*d?c*d:a*b);}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:45: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a,b,c,d){scanf("%d%d%d%d",&a,&b,&c,&d);printf("%d",a*b<c*d?c*d:a*b);}
                                 ...