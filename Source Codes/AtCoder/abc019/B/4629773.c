n;b;main(a){for(;~(a=getchar());b=a)b&&a-b?printf("%c%d",b,n),n=1:++n;puts("");} ./Main.c:1:1: warning: data definition has no type or storage class
 n;b;main(a){for(;~(a=getchar());b=a)b&&a-b?printf("%c%d",b,n),n=1:++n;puts("");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 n;b;main(a){for(;~(a=getchar());b=a)b&&a-b?printf("%c%d",b,n),n=1:++n;puts("");}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 n;b;main(a){for(;~(a=getchar());b=a)b&&a-b?printf("%c%d",b,n),n=1:++n;puts("");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:22: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 n;b;main(a){for(;~(a=getchar());b=a)b&&a-b?printf("%c%d",b,n),n=1:++n;puts("");}
                      ^
./Main.c:1:44: warning: implicit declaration of function ‘printf’ [-Wimplicit-fu...