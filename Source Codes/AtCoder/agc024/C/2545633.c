b=-1;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 b=-1;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 b=-1;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
               ^
./Main.c: In function ‘main’:
./Main.c:1:15: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:27: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 b=-1;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
                           ^
./Main.c:1:27: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:27: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:86: warning: implicit declaration of function ‘print...