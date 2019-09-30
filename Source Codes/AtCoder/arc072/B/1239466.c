long a,b;main(){scanf("%lld%lld",&a,&b);puts(abs(a-b)<2?"Brown":"Alice");} ./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long a,b;main(){scanf("%lld%lld",&a,&b);puts(abs(a-b)<2?"Brown":"Alice");}
          ^
./Main.c: In function ‘main’:
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long a,b;main(){scanf("%lld%lld",&a,&b);puts(abs(a-b)<2?"Brown":"Alice");}
                 ^
./Main.c:1:17: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:17: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:23: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘long int *’ [-Wformat=]
 long a,b;main(){scanf("%lld%lld",&a,&b);puts(abs(a-b)<2?"Brown":"Alice");}
                       ^
./Main.c:1:23: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 3 has type ‘long int *’ [-Wformat=]
./Main.c:1:41: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 long a,b;main()...