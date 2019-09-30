t;main(c){for(;(c=getchar_unlocked())>10;)t+=c%11-3;printf("%d",t>>1);} ./Main.c:1:1: warning: data definition has no type or storage class
 t;main(c){for(;(c=getchar_unlocked())>10;)t+=c%11-3;printf("%d",t>>1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 t;main(c){for(;(c=getchar_unlocked())>10;)t+=c%11-3;printf("%d",t>>1);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘getchar_unlocked’ [-Wimplicit-function-declaration]
 t;main(c){for(;(c=getchar_unlocked())>10;)t+=c%11-3;printf("%d",t>>1);}
                   ^
./Main.c:1:53: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 t;main(c){for(;(c=getchar_unlocked())>10;)t+=c%11-3;printf("%d",t>>1);}
                                                     ^
./Main.c:1:53: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:53: note: includ...