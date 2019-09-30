long n,k,c,b;main(){scanf("%d%d",&n,&k);n++;for(b=k;++b<n;)c+=n/b*(b-k)-!k+fdim(n,n/b*b+k);printf("%ld",c);} ./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long n,k,c,b;main(){scanf("%d%d",&n,&k);n++;for(b=k;++b<n;)c+=n/b*(b-k)-!k+fdim(n,n/b*b+k);printf("%ld",c);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:21: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long n,k,c,b;main(){scanf("%d%d",&n,&k);n++;for(b=k;++b<n;)c+=n/b*(b-k)-!k+fdim(n,n/b*b+k);printf("%ld",c);}
                     ^
./Main.c:1:21: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:21: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:27: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long n,k,c,b;main(){scanf("%d%d",&n,&k);n++;for(b=k;++b<n;)c+=n/b*(b-k)-!k+fdim(n,n/b*b+k);printf("%ld",c);}
                           ^
./Main.c:1:27: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:1:76: warning: ...