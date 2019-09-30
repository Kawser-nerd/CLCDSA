a[];main(i){for(;~scanf("%d",++i+a);)i>4?a[4]+=1+~-a[3]/a[i]:0;printf("%d",a[4]);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[];main(i){for(;~scanf("%d",++i+a);)i>4?a[4]+=1+~-a[3]/a[i]:0;printf("%d",a[4]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a[];main(i){for(;~scanf("%d",++i+a);)i>4?a[4]+=1+~-a[3]/a[i]:0;printf("%d",a[4]);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a[];main(i){for(;~scanf("%d",++i+a);)i>4?a[4]+=1+~-a[3]/a[i]:0;printf("%d",a[4]);}
                   ^
./Main.c:1:19: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:19: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:64: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 a[];main(i){for(;~scanf("%d",++i+a);)i>4?a[4]+=1+~-a[3...