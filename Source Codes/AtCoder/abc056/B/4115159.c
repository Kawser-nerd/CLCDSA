main(a,b,c){scanf("%d%d%d",&a,&b,&c);printf("%d",a+b<c?c-a-b:a+c<b?b-a-c:0);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b,c){scanf("%d%d%d",&a,&b,&c);printf("%d",a+b<c?c-a-b:a+c<b?b-a-c:0);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b,c){scanf("%d%d%d",&a,&b,&c);printf("%d",a+b<c?c-a-b:a+c<b?b-a-c:0);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a,b,c){scanf("%d%d%d",&a,&b,&c);printf("%d",a+b<c?c-a-b:a+c<b?b-a-c:0);}
                                      ^
./Main.c:1:38: warning: incompatible implicit declaratio...