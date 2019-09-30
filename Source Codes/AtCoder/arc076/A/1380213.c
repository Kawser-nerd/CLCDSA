long N,M,a,i,m=1e9+7;long f(int A){return A?A*f(A-1)%m:1;}main(){scanf("%d%d",&N,&M);printf("%d",(M^N?M>N+1||M<N-1?0:1:2)*f(N)*f(M)%m);} ./Main.c:1:59: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long N,M,a,i,m=1e9+7;long f(int A){return A?A*f(A-1)%m:1;}main(){scanf("%d%d",&N,&M);printf("%d",(M^N?M>N+1||M<N-1?0:1:2)*f(N)*f(M)%m);}
                                                           ^
./Main.c: In function ‘main’:
./Main.c:1:66: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long N,M,a,i,m=1e9+7;long f(int A){return A?A*f(A-1)%m:1;}main(){scanf("%d%d",&N,&M);printf("%d",(M^N?M>N+1||M<N-1?0:1:2)*f(N)*f(M)%m);}
                                                                  ^
./Main.c:1:66: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:66: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:72: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long N,M,a,i,m=1e9+7;long f(int A){return A?A*f(A-1)%m:1;}main(){scanf("%d%d",&N,&M);printf("%d",(M^N?M>N+1||M<N-1?0:1:2)*f(N)*f(M)%m);...