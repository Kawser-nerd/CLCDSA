c;d;main(n){for(scanf("%d %c",&n,&d);(c=getchar())>10;d=c)c>99|(c-d+2)%3?n=0:0;printf("%d\n",(d*4-9+n)%6?-1:n/2);} ./Main.c:1:1: warning: data definition has no type or storage class
 c;d;main(n){for(scanf("%d %c",&n,&d);(c=getchar())>10;d=c)c>99|(c-d+2)%3?n=0:0;printf("%d\n",(d*4-9+n)%6?-1:n/2);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 c;d;main(n){for(scanf("%d %c",&n,&d);(c=getchar())>10;d=c)c>99|(c-d+2)%3?n=0:0;printf("%d\n",(d*4-9+n)%6?-1:n/2);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c;d;main(n){for(scanf("%d %c",&n,&d);(c=getchar())>10;d=c)c>99|(c-d+2)%3?n=0:0;printf("%d\n",(d*4-9+n)%6?-1:n/2);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 c;d;main(n){for(scanf("%d %c",&n,&d);(c=getchar())>10;d=c)c>99|(c-d+2)%3?n=0:0;printf...