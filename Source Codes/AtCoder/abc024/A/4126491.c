main(a,b,c,k,s,t){scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);printf("%d\n",s+t<k?s*a+t*b:s*a+t*b-s*c-t*c);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b,c,k,s,t){scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);printf("%d\n",s+t<k?s*a+t*b:s*a+t*b-s*c-t*c);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘t’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b,c,k,s,t){scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);printf("%d\n",s+t<k?s*a+t*b:s*a+t*b-s*c-t*c);}
                   ^
./Main.c:1:19: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:19: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Mai...