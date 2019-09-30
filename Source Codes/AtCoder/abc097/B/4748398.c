p;m;main(i,x){for(scanf("%d",&x);++i<x;)for(p=i;p*=i,p<=x;)m=p>m?p:m;printf("%d",x<4?1:m);} ./Main.c:1:1: warning: data definition has no type or storage class
 p;m;main(i,x){for(scanf("%d",&x);++i<x;)for(p=i;p*=i,p<=x;)m=p>m?p:m;printf("%d",x<4?1:m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘p’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 p;m;main(i,x){for(scanf("%d",&x);++i<x;)for(p=i;p*=i,p<=x;)m=p>m?p:m;printf("%d",x<4?1:m);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 p;m;main(i,x){for(scanf("%d",&x);++i<x;)for(p=i;p*=i,p<=x;)m=p>m?p:m;printf("%d",x<4?1:m);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:19: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 p;m;main(i,x){for(scanf("%d",&x);++i<x;)for(p=i;p*=i,p<=x;)m=p>m?p:m;printf("%d",x<4...