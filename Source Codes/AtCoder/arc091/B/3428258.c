long n,k,c;main(b){scanf("%d%d",&n,&k);for(b=k;b++<n;)c+=n/b*(b-k)+fdim(n%b,k-!!k);printf("%ld",c);} ./Main.c:1:12: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long n,k,c;main(b){scanf("%d%d",&n,&k);for(b=k;b++<n;)c+=n/b*(b-k)+fdim(n%b,k-!!k);printf("%ld",c);}
            ^
./Main.c: In function ‘main’:
./Main.c:1:12: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:20: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long n,k,c;main(b){scanf("%d%d",&n,&k);for(b=k;b++<n;)c+=n/b*(b-k)+fdim(n%b,k-!!k);printf("%ld",c);}
                    ^
./Main.c:1:20: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:20: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:26: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long n,k,c;main(b){scanf("%d%d",&n,&k);for(b=k;b++<n;)c+=n/b*(b-k)+fdim(n%b,k-!!k);printf("%ld",c);}
                          ^
./Main.c:1:26: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long ...