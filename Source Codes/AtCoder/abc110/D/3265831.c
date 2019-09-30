long N,M,c,n=1,m=1e9+7,h,r,d;main(i){for(scanf("%d%d",&N,&M);M/++i/i;n=n*r%m){for(;M%i<1;++c)M/=i;for(r=d=1;c;r=r*(N+c)%m)d=d*c--%m;for(h=2*m-4;h/=2;d=d*d%m)r=h%2?r*d%m:r;}printf("%d",n*(M>1?N:1)%m);} ./Main.c:1:30: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long N,M,c,n=1,m=1e9+7,h,r,d;main(i){for(scanf("%d%d",&N,&M);M/++i/i;n=n*r%m){for(;M%i<1;++c)M/=i;for(r=d=1;c;r=r*(N+c)%m)d=d*c--%m;for(h=2*m-4;h/=2;d=d*d%m)r=h%2?r*d%m:r;}printf("%d",n*(M>1?N:1)%m);}
                              ^
./Main.c: In function ‘main’:
./Main.c:1:30: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:42: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long N,M,c,n=1,m=1e9+7,h,r,d;main(i){for(scanf("%d%d",&N,&M);M/++i/i;n=n*r%m){for(;M%i<1;++c)M/=i;for(r=d=1;c;r=r*(N+c)%m)d=d*c--%m;for(h=2*m-4;h/=2;d=d*d%m)r=h%2?r*d%m:r;}printf("%d",n*(M>1?N:1)%m);}
                                          ^
./Main.c:1:42: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:42: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:48: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-...