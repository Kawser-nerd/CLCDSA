b=-1;long s;main(a){for(scanf("%*d");~scanf("%d",&a);b=a)s=s<0||b+1<a?~a:b<a?s:s+b;printf("%ld",s+b);} ./Main.c:1:1: warning: data definition has no type or storage class
 b=-1;long s;main(a){for(scanf("%*d");~scanf("%d",&a);b=a)s=s<0||b+1<a?~a:b<a?s:s+b;printf("%ld",s+b);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 b=-1;long s;main(a){for(scanf("%*d");~scanf("%d",&a);b=a)s=s<0||b+1<a?~a:b<a?s:s+b;printf("%ld",s+b);}
             ^
./Main.c: In function ‘main’:
./Main.c:1:13: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:25: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 b=-1;long s;main(a){for(scanf("%*d");~scanf("%d",&a);b=a)s=s<0||b+1<a?~a:b<a?s:s+b;printf("%ld",s+b);}
                         ^
./Main.c:1:25: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:25: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:84: warning: implicit declaration of function ‘printf’ [-Wimplicit-f...