x;M;main(s){for(gets(&s);s=getchar()-10;M=--x>M?x:M)x+=s%2*2;printf("%d",M);} ./Main.c:1:1: warning: data definition has no type or storage class
 x;M;main(s){for(gets(&s);s=getchar()-10;M=--x>M?x:M)x+=s%2*2;printf("%d",M);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 x;M;main(s){for(gets(&s);s=getchar()-10;M=--x>M?x:M)x+=s%2*2;printf("%d",M);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 x;M;main(s){for(gets(&s);s=getchar()-10;M=--x>M?x:M)x+=s%2*2;printf("%d",M);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 x;M;main(s){for(gets(&s);s=getchar()-10;M=--x>M?x:M)x+=s%2*2;printf("%d",M);}
                 ^
./Main.c:1:28: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]...