main(a,b,c){scanf("%d %s %d",&a,&b,&c);printf("%d",b&2?a+c:a-c);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b,c){scanf("%d %s %d",&a,&b,&c);printf("%d",b&2?a+c:a-c);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b,c){scanf("%d %s %d",&a,&b,&c);printf("%d",b&2?a+c:a-c);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:19: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘int *’ [-Wformat=]
 main(a,b,c){scanf("%d %s %d",&a,&b,&c);printf("%d",b&2?a+c:a-c);}
                   ^
./Main.c:1:40: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declarati...