long long n;main(a){scanf("%lld",&n);for(n++;n>9;n/=10)a+=9;printf("%d\n",n+a-2);} ./Main.c:1:13: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long long n;main(a){scanf("%lld",&n);for(n++;n>9;n/=10)a+=9;printf("%d\n",n+a-2);}
             ^
./Main.c: In function ‘main’:
./Main.c:1:13: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:21: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long long n;main(a){scanf("%lld",&n);for(n++;n>9;n/=10)a+=9;printf("%d\n",n+a-2);}
                     ^
./Main.c:1:21: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:21: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:61: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 long long n;main(a){scanf("%lld",&n);for(n++;n>9;n/=10)a+=9;printf("%d\n",n+a-2);}
                                                             ^
./Main.c:1:61: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:61: note: include ‘<stdio.h>’ or prov...