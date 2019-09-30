s;main(a){for(gets(&a);~(scanf("%d",&a));s+=(a<5|6<a?:3)-a%2);printf("%d\n",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 s;main(a){for(gets(&a);~(scanf("%d",&a));s+=(a<5|6<a?:3)-a%2);printf("%d\n",s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s;main(a){for(gets(&a);~(scanf("%d",&a));s+=(a<5|6<a?:3)-a%2);printf("%d\n",s);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 s;main(a){for(gets(&a);~(scanf("%d",&a));s+=(a<5|6<a?:3)-a%2);printf("%d\n",s);}
               ^
./Main.c:1:26: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 s;main(a){for(gets(&a);~(scanf("%d",&a));s+=(a<5|6<a?:3)-a%2);printf("%d\n",s);}
                          ^
./Main.c:1:26: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:26: note: include ‘<stdio...