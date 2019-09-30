long a;main(v){for(;~scanf("%d",&a);)v=v*a%1000000007;printf("%d",v);} ./Main.c:1:8: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long a;main(v){for(;~scanf("%d",&a);)v=v*a%1000000007;printf("%d",v);}
        ^
./Main.c: In function ‘main’:
./Main.c:1:8: warning: type of ‘v’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:22: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long a;main(v){for(;~scanf("%d",&a);)v=v*a%1000000007;printf("%d",v);}
                      ^
./Main.c:1:22: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:22: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:28: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long a;main(v){for(;~scanf("%d",&a);)v=v*a%1000000007;printf("%d",v);}
                            ^
./Main.c:1:55: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 long a;main(v){for(;~scanf("%d",&a);)v=v*a%1000000007;printf("%d",v);}
                    ...