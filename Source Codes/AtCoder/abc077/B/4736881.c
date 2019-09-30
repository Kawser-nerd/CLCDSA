k;main(n){for(scanf("%d",&n);++k*k<=n;);printf("%d",--k*k);} ./Main.c:1:1: warning: data definition has no type or storage class
 k;main(n){for(scanf("%d",&n);++k*k<=n;);printf("%d",--k*k);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 k;main(n){for(scanf("%d",&n);++k*k<=n;);printf("%d",--k*k);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 k;main(n){for(scanf("%d",&n);++k*k<=n;);printf("%d",--k*k);}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:41: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 k;main(n){for(scanf("%d",&n);++k*k<=n;);printf("%d",--k*k);}
                                         ^
./Main.c:1:41: warning...