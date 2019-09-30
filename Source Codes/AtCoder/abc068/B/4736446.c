main(n,N){for(scanf("%d",&N);n<=N;n*=2);printf("%d",n/2);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,N){for(scanf("%d",&N);n<=N;n*=2);printf("%d",n/2);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘N’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(n,N){for(scanf("%d",&N);n<=N;n*=2);printf("%d",n/2);}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:41: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(n,N){for(scanf("%d",&N);n<=N;n*=2);printf("%d",n/2);}
                                         ^
./Main.c:1:41: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:41: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’