i=3;main(n,j){for(scanf("%d",&n);j=n-i+1&~1,n>3&5000<j;i+=3);for(i=n-j;i;printf(n<4?i=0,"2 3 25":"%d ",2*i--))for(;j;printf("%d ",6*j---3));} ./Main.c:1:1: warning: data definition has no type or storage class
 i=3;main(n,j){for(scanf("%d",&n);j=n-i+1&~1,n>3&5000<j;i+=3);for(i=n-j;i;printf(n<4?i=0,"2 3 25":"%d ",2*i--))for(;j;printf("%d ",6*j---3));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i=3;main(n,j){for(scanf("%d",&n);j=n-i+1&~1,n>3&5000<j;i+=3);for(i=n-j;i;printf(n<4?i=0,"2 3 25":"%d ",2*i--))for(;j;printf("%d ",6*j---3));}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘j’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i=3;main(n,j){for(scanf("%d",&n);j=n-i+1&~1,n>3&5000<j;i+=3);for(i=n-j;i;printf(n<4?i=0,"2 3 25":"%d ",2*i--))for(;j;printf("%d ",6*j---3));}
                   ^
./Main.c:1:19: warning: incompatible implicit declaration of built-in fu...