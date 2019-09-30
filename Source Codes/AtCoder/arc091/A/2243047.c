long n;main(m){scanf("%ld%d",&n,&m);n=(n-2)*(m-2);printf("%ld",n>0?n:-n);} ./Main.c:1:8: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long n;main(m){scanf("%ld%d",&n,&m);n=(n-2)*(m-2);printf("%ld",n>0?n:-n);}
        ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:16: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long n;main(m){scanf("%ld%d",&n,&m);n=(n-2)*(m-2);printf("%ld",n>0?n:-n);}
                ^
./Main.c:1:16: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:16: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:51: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 long n;main(m){scanf("%ld%d",&n,&m);n=(n-2)*(m-2);printf("%ld",n>0?n:-n);}
                                                   ^
./Main.c:1:51: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:51: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’