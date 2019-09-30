long x,s,t;main(n){for(scanf("%d%ld",&n,&x);~n;x-=x>t-2?s+=t/2,t-1:1)t=2L<<n--;printf("%ld",s);} ./Main.c:1:12: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long x,s,t;main(n){for(scanf("%d%ld",&n,&x);~n;x-=x>t-2?s+=t/2,t-1:1)t=2L<<n--;printf("%ld",s);}
            ^
./Main.c: In function ‘main’:
./Main.c:1:12: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:24: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long x,s,t;main(n){for(scanf("%d%ld",&n,&x);~n;x-=x>t-2?s+=t/2,t-1:1)t=2L<<n--;printf("%ld",s);}
                        ^
./Main.c:1:24: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:24: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:80: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 long x,s,t;main(n){for(scanf("%d%ld",&n,&x);~n;x-=x>t-2?s+=t/2,t-1:1)t=2L<<n--;printf("%ld",s);}
                                                                                ^
./Main.c:1:80: warning: incompatible implicit declaration of built-in fun...