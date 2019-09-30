y;main(s,e){for(;~scanf("%d%d",&s,&e);y+=s*e/10);printf("%d\n",y);} ./Main.c:1:1: warning: data definition has no type or storage class
 y;main(s,e){for(;~scanf("%d%d",&s,&e);y+=s*e/10);printf("%d\n",y);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘y’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 y;main(s,e){for(;~scanf("%d%d",&s,&e);y+=s*e/10);printf("%d\n",y);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘e’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 y;main(s,e){for(;~scanf("%d%d",&s,&e);y+=s*e/10);printf("%d\n",y);}
                   ^
./Main.c:1:19: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:19: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:50: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 y;main(s,e){for(;~scanf("%d%d",...