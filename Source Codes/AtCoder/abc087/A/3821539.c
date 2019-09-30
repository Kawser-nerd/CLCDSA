b;main(x,a){scanf("%d%d%d",&x,&a,&b);printf("%d",(x-a)%b);} ./Main.c:1:1: warning: data definition has no type or storage class
 b;main(x,a){scanf("%d%d%d",&x,&a,&b);printf("%d",(x-a)%b);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 b;main(x,a){scanf("%d%d%d",&x,&a,&b);printf("%d",(x-a)%b);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 b;main(x,a){scanf("%d%d%d",&x,&a,&b);printf("%d",(x-a)%b);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 b;main(x,a){scanf("%d%d%d",&x,&a,&b);printf("%d",(x-a)%b);}
 ...