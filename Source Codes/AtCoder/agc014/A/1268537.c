s,d,e;main(a,b,c){for(scanf("%d%d%d",&a,&b,&c);a%2+b%2+c%2<1&s<30;a=b+c>>1,b=d+c>>1,c=d+e>>1)d=a,e=b,s++;printf("%d",s<30?s:-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 s,d,e;main(a,b,c){for(scanf("%d%d%d",&a,&b,&c);a%2+b%2+c%2<1&s<30;a=b+c>>1,b=d+c>>1,c=d+e>>1)d=a,e=b,s++;printf("%d",s<30?s:-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 s,d,e;main(a,b,c){for(scanf("%d%d%d",&a,&b,&c);a%2+b%2+c%2<1&s<30;a=b+c>>1,b=d+c>>1,c=d+e>>1)d=a,e=b,s++;printf("%d",s<30?s:-1);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘e’ [-Wimplicit-int]
 s,d,e;main(a,b,c){for(scanf("%d%d%d",&a,&b,&c);a%2+b%2+c%2<1&s<30;a=b+c>>1,b=d+c>>1,c=d+e>>1)d=a,e=b,s++;printf("%d",s<30?s:-1);}
     ^
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 s,d,e;main(a,b,c){for(scanf("%d%d%d",&a,&b,&c);a%2+b%2+c%2<1&s<30;a=b+c>>1,b=d+c>>1,c=d+e>>1)d=a,e=b,s++;printf("%d",s<30?s:-1);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘a’ defaults to ‘int’ ...