a[999];main(i){for(;i<5|a[i]<a[4]&&~scanf("%d",++i+a););i-=5;printf("%.f",fmin(i,a[3]-i));} ./Main.c:1:1: warning: data definition has no type or storage class
 a[999];main(i){for(;i<5|a[i]<a[4]&&~scanf("%d",++i+a););i-=5;printf("%.f",fmin(i,a[3]-i));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:8: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a[999];main(i){for(;i<5|a[i]<a[4]&&~scanf("%d",++i+a););i-=5;printf("%.f",fmin(i,a[3]-i));}
        ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:37: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a[999];main(i){for(;i<5|a[i]<a[4]&&~scanf("%d",++i+a););i-=5;printf("%.f",fmin(i,a[3]-i));}
                                     ^
./Main.c:1:37: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:37: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:62: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 a[999]...