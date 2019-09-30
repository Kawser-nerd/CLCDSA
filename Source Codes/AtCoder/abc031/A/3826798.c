main(){int n[2];scanf("%d %d", n, n+1);printf("%d\n", ((n[0]+1)*n[1]<n[0]*(n[1]+1)?n[0]*(n[1]+1):(n[0]+1)*n[1]));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int n[2];scanf("%d %d", n, n+1);printf("%d\n", ((n[0]+1)*n[1]<n[0]*(n[1]+1)?n[0]*(n[1]+1):(n[0]+1)*n[1]));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(){int n[2];scanf("%d %d", n, n+1);printf("%d\n", ((n[0]+1)*n[1]<n[0]*(n[1]+1)?n[0]*(n[1]+1):(n[0]+1)*n[1]));}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:40: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(){int n[2];scanf("%d %d", n, n+1);printf("%d\n", ((n[0]+1)*n[1]<n[0]*(n[1]+1)?n[0]*(n[1]+1):(n[0]+1)*n[1]));}
                                        ^
./Main.c:1:40: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:40: note: include ‘<stdio.h>’ or provide a declara...