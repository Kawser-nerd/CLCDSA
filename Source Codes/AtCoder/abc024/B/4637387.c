a,b=1<<31,u;main(t){for(scanf("%*d%d",&t);~scanf("%d",&a);b=a)u+=b+t<a?t:a-b;printf("%d\n",u);} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b=1<<31,u;main(t){for(scanf("%*d%d",&t);~scanf("%d",&a);b=a)u+=b+t<a?t:a-b;printf("%d\n",u);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b=1<<31,u;main(t){for(scanf("%*d%d",&t);~scanf("%d",&a);b=a)u+=b+t<a?t:a-b;printf("%d\n",u);}
   ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
 a,b=1<<31,u;main(t){for(scanf("%*d%d",&t);~scanf("%d",&a);b=a)u+=b+t<a?t:a-b;printf("%d\n",u);}
           ^
./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b=1<<31,u;main(t){for(scanf("%*d%d",&t);~scanf("%d",&a);b=a)u+=b+t<a?t:a-b;printf("%d\n",u);}
             ^
./Main.c: In function ‘main’:
./Main.c:1:13: warning: type of ‘t’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:25: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a,b=...