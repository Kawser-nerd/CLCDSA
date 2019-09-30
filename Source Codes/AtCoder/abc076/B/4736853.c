main(m,n,k){for(scanf("%d%d",&n,&k);n--;)m+=m>k?k:m;printf("%d",m);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(m,n,k){for(scanf("%d%d",&n,&k);n--;)m+=m>k?k:m;printf("%d",m);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(m,n,k){for(scanf("%d%d",&n,&k);n--;)m+=m>k?k:m;printf("%d",m);}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:53: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(m,n,k){for(scanf("%d%d",&n,&k);n--;)m+=m>k?k:m;printf("%d",m);}
                                                     ^
./Main.c:1:53: warning: incompatible implicit declaration of bui...