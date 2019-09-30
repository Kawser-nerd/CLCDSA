a;main(b){for(;b>0;b=getchar()-94)a|=b-5?5083%b:getchar()-'h';puts(a?"NO":"YES");} ./Main.c:1:1: warning: data definition has no type or storage class
 a;main(b){for(;b>0;b=getchar()-94)a|=b-5?5083%b:getchar()-'h';puts(a?"NO":"YES");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;main(b){for(;b>0;b=getchar()-94)a|=b-5?5083%b:getchar()-'h';puts(a?"NO":"YES");}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:22: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 a;main(b){for(;b>0;b=getchar()-94)a|=b-5?5083%b:getchar()-'h';puts(a?"NO":"YES");}
                      ^
./Main.c:1:63: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 a;main(b){for(;b>0;b=getchar()-94)a|=b-5?5083%b:getchar()-'h';puts(a?"NO":"YES");}
                                                               ^