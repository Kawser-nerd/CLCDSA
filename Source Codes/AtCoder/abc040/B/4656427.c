m=99;v;l;main(n){for(scanf("%d",&n);++l<=n;m=v<m?v:m)v=n-n/l*l+abs(l-n/l);printf("%d",m);} ./Main.c:1:1: warning: data definition has no type or storage class
 m=99;v;l;main(n){for(scanf("%d",&n);++l<=n;m=v<m?v:m)v=n-n/l*l+abs(l-n/l);printf("%d",m);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:6: warning: data definition has no type or storage class
 m=99;v;l;main(n){for(scanf("%d",&n);++l<=n;m=v<m?v:m)v=n-n/l*l+abs(l-n/l);printf("%d",m);}
      ^
./Main.c:1:6: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 m=99;v;l;main(n){for(scanf("%d",&n);++l<=n;m=v<m?v:m)v=n-n/l*l+abs(l-n/l);printf("%d",m);}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
./Main.c:1:10: warning: return type defaults to ‘int’ [-Wimplicit-int]
 m=99;v;l;main(n){for(scanf("%d",&n);++l<=n;m=v<m?v:m)v=n-n/l*l+abs(l-n/l);printf("%d",m);}
          ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: type of ‘n’ defaults to ‘int’ [-Wimplic...