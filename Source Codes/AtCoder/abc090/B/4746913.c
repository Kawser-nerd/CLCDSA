c;main(a,b){for(scanf("%d%d",&a,&b);a<=b;)a%100-a/10000-a++/1000%10*10?:c++;printf("%d",c);} ./Main.c:1:1: warning: data definition has no type or storage class
 c;main(a,b){for(scanf("%d%d",&a,&b);a<=b;)a%100-a/10000-a++/1000%10*10?:c++;printf("%d",c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c;main(a,b){for(scanf("%d%d",&a,&b);a<=b;)a%100-a/10000-a++/1000%10*10?:c++;printf("%d",c);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 c;main(a,b){for(scanf("%d%d",&a,&b);a<=b;)a%100-a/10000-a++/1000%10*10?:c++;printf("%d",c);}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:77: warning: implicit declaration of function ‘p...