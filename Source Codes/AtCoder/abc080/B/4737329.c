h;main(i,N){for(scanf("%d",&N);i<=N;i*=10)h+=N/i%10;puts(N%h?"No":"Yes");} ./Main.c:1:1: warning: data definition has no type or storage class
 h;main(i,N){for(scanf("%d",&N);i<=N;i*=10)h+=N/i%10;puts(N%h?"No":"Yes");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 h;main(i,N){for(scanf("%d",&N);i<=N;i*=10)h+=N/i%10;puts(N%h?"No":"Yes");}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘N’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 h;main(i,N){for(scanf("%d",&N);i<=N;i*=10)h+=N/i%10;puts(N%h?"No":"Yes");}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:53: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 h;main(i,N){fo...