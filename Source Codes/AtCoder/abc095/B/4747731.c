l=1e9;main(n,x,m){for(scanf("%d%d",&n,&x);~scanf("%d",&m);l=m<l?m:l)x-=m;printf("%d",n+x/l);} ./Main.c:1:1: warning: data definition has no type or storage class
 l=1e9;main(n,x,m){for(scanf("%d%d",&n,&x);~scanf("%d",&m);l=m<l?m:l)x-=m;printf("%d",n+x/l);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 l=1e9;main(n,x,m){for(scanf("%d%d",&n,&x);~scanf("%d",&m);l=m<l?m:l)x-=m;printf("%d",n+x/l);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:7: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:7: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 l=1e9;main(n,x,m){for(scanf("%d%d",&n,&x);~scanf("%d",&m);l=m<l?m:l)x-=m;printf("%d",n+x/l);}
                       ^
./Main.c:1:23: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:23: note: include ‘<stdio.h>’ or provide a...