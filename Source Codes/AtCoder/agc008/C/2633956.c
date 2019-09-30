main(I,O,J,L,d){scanf("%d%d%*d%d%d",&I,&O,&J,&L);printf("%lld",(long long)O+I+J+L-(1<(d=I%2+J%2+L%2)&&I&&J&&L?3-d:d));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(I,O,J,L,d){scanf("%d%d%*d%d%d",&I,&O,&J,&L);printf("%lld",(long long)O+I+J+L-(1<(d=I%2+J%2+L%2)&&I&&J&&L?3-d:d));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘I’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘O’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘J’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘L’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(I,O,J,L,d){scanf("%d%d%*d%d%d",&I,&O,&J,&L);printf("%lld",(long long)O+I+J+L-(1<(d=I%2+J%2+L%2)&&I&&J&&L?3-d:d));}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:50: warning: implicit declaration of...