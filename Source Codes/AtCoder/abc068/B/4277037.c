i=1;main(n){scanf("%d",&n);while(i<=n)i*=2;printf("%d",i/2);} ./Main.c:1:1: warning: data definition has no type or storage class
 i=1;main(n){scanf("%d",&n);while(i<=n)i*=2;printf("%d",i/2);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i=1;main(n){scanf("%d",&n);while(i<=n)i*=2;printf("%d",i/2);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i=1;main(n){scanf("%d",&n);while(i<=n)i*=2;printf("%d",i/2);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:44: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 i=1;main(n){scanf("%d",&n);while(i<=n)i*=2;printf("%d",i/2);}
                                            ^
./Main.c:1:44: ...