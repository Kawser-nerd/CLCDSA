m;s;main(a,b,c,k){scanf("%d%d%d%d",&a,&b,&c,&k);m=a<b?b<c?c:b:a<c?c:a;s=a+b+c+(m<<k)-m;printf("%d",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 m;s;main(a,b,c,k){scanf("%d%d%d%d",&a,&b,&c,&k);m=a<b?b<c?c:b:a<c?c:a;s=a+b+c+(m<<k)-m;printf("%d",s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘m’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 m;s;main(a,b,c,k){scanf("%d%d%d%d",&a,&b,&c,&k);m=a<b?b<c?c:b:a<c?c:a;s=a+b+c+(m<<k)-m;printf("%d",s);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 m;s;main(a,b,c,k){scanf("%d%d%d%d",&a,&b,&c,&k);m=a<b?b<c?c:b:a<c?c:a;s=a+b+c+(m<<k)-m;printf("%d",s);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c...