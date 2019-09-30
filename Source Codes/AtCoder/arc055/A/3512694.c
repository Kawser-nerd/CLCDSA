i;main(n){scanf("%d",&n);printf("1");for(;i++<n-1;)printf("0");puts("7");} ./Main.c:1:1: warning: data definition has no type or storage class
 i;main(n){scanf("%d",&n);printf("1");for(;i++<n-1;)printf("0");puts("7");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i;main(n){scanf("%d",&n);printf("1");for(;i++<n-1;)printf("0");puts("7");}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i;main(n){scanf("%d",&n);printf("1");for(;i++<n-1;)printf("0");puts("7");}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:26: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 i;main(n){scanf("%d",&n);printf("1");for(;i++<n-1;)printf("0");puts("7");}
             ...