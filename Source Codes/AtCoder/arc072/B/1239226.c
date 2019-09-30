long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");} ./Main.c:1:15: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
               ^
./Main.c: In function ‘main’:
./Main.c:1:22: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
                      ^
./Main.c:1:22: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:22: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:49: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=1)printf("Brown\n");else printf("Alice\n");}
                                                 ^
./Main.c:1:61: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 long long a,b;main(){scanf("%lld%lld",&a,&b);if(abs(a-b)<=...