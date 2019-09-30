#define L long long
L F(L A,L B){return B?A/B*B*2+F(B,A%B):-A;}
main(){L N,X;scanf("%lld%lld",&N,&X);printf("%lld",N+F(N-X,X));} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){L N,X;scanf("%lld%lld",&N,&X);printf("%lld",N+F(N-X,X));}
 ^
./Main.c: In function ‘main’:
./Main.c:3:14: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(){L N,X;scanf("%lld%lld",&N,&X);printf("%lld",N+F(N-X,X));}
              ^
./Main.c:3:14: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:14: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(){L N,X;scanf("%lld%lld",&N,&X);printf("%lld",N+F(N-X,X));}
                                      ^
./Main.c:3:38: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:3:38: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’