t[1<<20];i=3;main(n){t[2]=1;for(scanf("%d",&n);i<n;t[i]=(t[i-1]+t[i-2]+t[i++-3])%10007);printf("%d\n",t[n-1]);} ./Main.c:1:1: warning: data definition has no type or storage class
 t[1<<20];i=3;main(n){t[2]=1;for(scanf("%d",&n);i<n;t[i]=(t[i-1]+t[i-2]+t[i++-3])%10007);printf("%d\n",t[n-1]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 t[1<<20];i=3;main(n){t[2]=1;for(scanf("%d",&n);i<n;t[i]=(t[i-1]+t[i-2]+t[i++-3])%10007);printf("%d\n",t[n-1]);}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 t[1<<20];i=3;main(n){t[2]=1;for(scanf("%d",&n);i<n;t[i]=(t[i-1]+t[i-2]+t[i++-3])%10007);printf("%d\n",t[n-1]);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:33: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 t[1<<20];i=3;main(n){t[2]=1;for(scanf("%d",&n);i<n;t[i]=(t[i-1]+t[i-2]+t[i...