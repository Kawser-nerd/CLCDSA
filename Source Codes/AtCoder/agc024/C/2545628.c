i,b;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=a>i++||b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 i,b;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=a>i++||b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 i,b;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=a>i++||b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
   ^
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i,b;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=a>i++||b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:26: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i,b;long s=1;main(a){for(scanf("%*d");s>0&&~scanf("%d",&a);b=a)s=a>i++||b+1<a?-a:b<a?s:s+b;printf("%ld",s+b-1);}
                          ^
./Main....