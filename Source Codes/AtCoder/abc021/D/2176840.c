long M=1e9+7,s=1,t=1;
long p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}
main(i,a,b){scanf("%d%d",&a,&b);for(a+=b;b/i;t=t*i++%M)s=s*(a-i)%M;printf("%d\n",s*p(t,M-2)%M);} ./Main.c: In function ‘p’:
./Main.c:2:6: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
 long p(a,b)long a;{return b?p(a*a%M,b/2)*(b%2?a:1)%M:1;}
      ^
./Main.c: At top level:
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,a,b){scanf("%d%d",&a,&b);for(a+=b;b/i;t=t*i++%M)s=s*(a-i)%M;printf("%d\n",s*p(t,M-2)%M);}
 ^
./Main.c: In function ‘main’:
./Main.c:3:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(i,a,b){scanf("%d%d",&a,&b);for(a+=b;b/i;t=t*i++%M)s=s*(a-i)%M;printf("%d\n",s*p(t,M-2)%M);}
             ^
./Main.c:3:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:68: warning: implicit declaration of f...