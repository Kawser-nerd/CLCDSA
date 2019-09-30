c;main(a){for(;(a=getchar()-96)>0;)c^=1<<a;puts(c?"No":"Yes");} ./Main.c:1:1: warning: data definition has no type or storage class
 c;main(a){for(;(a=getchar()-96)>0;)c^=1<<a;puts(c?"No":"Yes");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c;main(a){for(;(a=getchar()-96)>0;)c^=1<<a;puts(c?"No":"Yes");}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 c;main(a){for(;(a=getchar()-96)>0;)c^=1<<a;puts(c?"No":"Yes");}
                   ^
./Main.c:1:44: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 c;main(a){for(;(a=getchar()-96)>0;)c^=1<<a;puts(c?"No":"Yes");}
                                            ^