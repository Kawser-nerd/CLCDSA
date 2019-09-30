long long a,b,c,d;main(){gets(&a);for(a=b=1;~scanf("%lld%lld",&c,&d);a=b*c+c,b=b*d+d)a=~-a/c,b=~-b/d,b<a&&(b=a);printf("%lld\n",a+b);} ./Main.c:1:19: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long long a,b,c,d;main(){gets(&a);for(a=b=1;~scanf("%lld%lld",&c,&d);a=b*c+c,b=b*d+d)a=~-a/c,b=~-b/d,b<a&&(b=a);printf("%lld\n",a+b);}
                   ^
./Main.c: In function ‘main’:
./Main.c:1:26: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 long long a,b,c,d;main(){gets(&a);for(a=b=1;~scanf("%lld%lld",&c,&d);a=b*c+c,b=b*d+d)a=~-a/c,b=~-b/d,b<a&&(b=a);printf("%lld\n",a+b);}
                          ^
./Main.c:1:46: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long long a,b,c,d;main(){gets(&a);for(a=b=1;~scanf("%lld%lld",&c,&d);a=b*c+c,b=b*d+d)a=~-a/c,b=~-b/d,b<a&&(b=a);printf("%lld\n",a+b);}
                                              ^
./Main.c:1:46: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:46: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:113: warning: implicit declaration of function...