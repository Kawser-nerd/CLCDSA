t=100;main(a){for(gets(&a);~scanf("%d",&a);t=a<t?a:t);printf("%d\n",t);} ./Main.c:1:1: warning: data definition has no type or storage class
 t=100;main(a){for(gets(&a);~scanf("%d",&a);t=a<t?a:t);printf("%d\n",t);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 t=100;main(a){for(gets(&a);~scanf("%d",&a);t=a<t?a:t);printf("%d\n",t);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 t=100;main(a){for(gets(&a);~scanf("%d",&a);t=a<t?a:t);printf("%d\n",t);}
                   ^
./Main.c:1:29: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 t=100;main(a){for(gets(&a);~scanf("%d",&a);t=a<t?a:t);printf("%d\n",t);}
                             ^
./Main.c:1:29: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:29: note: include ‘<stdio.h>’ or provide a dec...