a[26];long long x=1;main(n){for(scanf("%d ",&n);n--;)a[getchar()-97]++;for(;26-n;x=(x*a[n++])%1000000007)a[n]++;printf("%lld\n",x-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[26];long long x=1;main(n){for(scanf("%d ",&n);n--;)a[getchar()-97]++;for(;26-n;x=(x*a[n++])%1000000007)a[n]++;printf("%lld\n",x-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:21: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a[26];long long x=1;main(n){for(scanf("%d ",&n);n--;)a[getchar()-97]++;for(;26-n;x=(x*a[n++])%1000000007)a[n]++;printf("%lld\n",x-1);}
                     ^
./Main.c: In function ‘main’:
./Main.c:1:21: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:33: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a[26];long long x=1;main(n){for(scanf("%d ",&n);n--;)a[getchar()-97]++;for(;26-n;x=(x*a[n++])%1000000007)a[n]++;printf("%lld\n",x-1);}
                                 ^
./Main.c:1:33: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:33: note: include ‘<stdio.h>’ or ...