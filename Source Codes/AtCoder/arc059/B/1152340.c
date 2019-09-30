i,b;main(a,c){for(;c-b&&c-a&&~c;c=getchar(i++))a=b,b=c;printf("%d %d",c-b?c-a?-1:i-2:i-1,c-b&&c-a?-1:i);} ./Main.c:1:1: warning: data definition has no type or storage class
 i,b;main(a,c){for(;c-b&&c-a&&~c;c=getchar(i++))a=b,b=c;printf("%d %d",c-b?c-a?-1:i-2:i-1,c-b&&c-a?-1:i);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 i,b;main(a,c){for(;c-b&&c-a&&~c;c=getchar(i++))a=b,b=c;printf("%d %d",c-b?c-a?-1:i-2:i-1,c-b&&c-a?-1:i);}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i,b;main(a,c){for(;c-b&&c-a&&~c;c=getchar(i++))a=b,b=c;printf("%d %d",c-b?c-a?-1:i-2:i-1,c-b&&c-a?-1:i);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:35: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
 i,b;main(a,c){for(;c-b&&c-a&&~c;c=getchar(i++))a=b,b=c;printf("%d %d",c-b?c-a?-1:i-2:i-1,c-b&&c-a?-1:i);}
  ...