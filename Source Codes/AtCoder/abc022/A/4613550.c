n;w;main(s,t,a){scanf("%*d%d%d",&s,&t);for(;~scanf("%d",&a);(w+=a)<s|t<w?:n++);printf("%d\n",n);} ./Main.c:1:1: warning: data definition has no type or storage class
 n;w;main(s,t,a){scanf("%*d%d%d",&s,&t);for(;~scanf("%d",&a);(w+=a)<s|t<w?:n++);printf("%d\n",n);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 n;w;main(s,t,a){scanf("%*d%d%d",&s,&t);for(;~scanf("%d",&a);(w+=a)<s|t<w?:n++);printf("%d\n",n);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘w’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 n;w;main(s,t,a){scanf("%*d%d%d",&s,&t);for(;~scanf("%d",&a);(w+=a)<s|t<w?:n++);printf("%d\n",n);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘s’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘t’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:17: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaratio...