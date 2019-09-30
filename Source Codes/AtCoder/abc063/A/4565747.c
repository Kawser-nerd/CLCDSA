main(a,b){scanf("%d%d%d",&a,&b);printf(a+b>9?"error":"%d",a+b);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){scanf("%d%d%d",&a,&b);printf(a+b>9?"error":"%d",a+b);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d%d",&a,&b);printf(a+b>9?"error":"%d",a+b);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:17: warning: format ‘%d’ expects a matching ‘int *’ argument [-Wformat=]
 main(a,b){scanf("%d%d%d",&a,&b);printf(a+b>9?"error":"%d",a+b);}
                 ^
./Main.c:1:33: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d%d",&a,&b);printf(a+b>9?"error":"%d",a+b);}
                                 ^
./M...