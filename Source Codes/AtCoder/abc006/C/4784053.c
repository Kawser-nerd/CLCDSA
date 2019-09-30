a;c;main(n,m){scanf("%d%d",&n,&m);m-=3*n;n=abs(m)>n?a=c=-1:n-(m>0?c=m:(a=-m));printf("%d %d %d\n",a,n,c);} ./Main.c:1:1: warning: data definition has no type or storage class
 a;c;main(n,m){scanf("%d%d",&n,&m);m-=3*n;n=abs(m)>n?a=c=-1:n-(m>0?c=m:(a=-m));printf("%d %d %d\n",a,n,c);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 a;c;main(n,m){scanf("%d%d",&n,&m);m-=3*n;n=abs(m)>n?a=c=-1:n-(m>0?c=m:(a=-m));printf("%d %d %d\n",a,n,c);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;c;main(n,m){scanf("%d%d",&n,&m);m-=3*n;n=abs(m)>n?a=c=-1:n-(m>0?c=m:(a=-m));printf("%d %d %d\n",a,n,c);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a;c;main(n,m){scanf("%d%d",&n,&m);m-=3*...