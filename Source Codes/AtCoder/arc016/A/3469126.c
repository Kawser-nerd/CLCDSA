n;main(m){scanf("%d%d",&n,&m);printf("%d\n",m==1?n:m-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 n;main(m){scanf("%d%d",&n,&m);printf("%d\n",m==1?n:m-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 n;main(m){scanf("%d%d",&n,&m);printf("%d\n",m==1?n:m-1);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 n;main(m){scanf("%d%d",&n,&m);printf("%d\n",m==1?n:m-1);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:31: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 n;main(m){scanf("%d%d",&n,&m);printf("%d\n",m==1?n:m-1);}
                               ^
./Main.c:1:31: warning: incompatible implicit de...