a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b&&(f=1),a<b&&(t=1),f&t&&(f=t=0,s++);printf("%d",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b&&(f=1),a<b&&(t=1),f&t&&(f=t=0,s++);printf("%d",s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b&&(f=1),a<b&&(t=1),f&t&&(f=t=0,s++);printf("%d",s);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b&&(f=1),a<b&&(t=1),f&t&&(f=t=0,s++);printf("%d",s);}
     ^
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b&&(f=1),a<b&&(t=1),f&t&&(f=t=0,s++);printf("%d",s);}
       ^
./Main.c:1:9: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b,f,t;main(s){for(scanf("%*d%d",&a);~scanf("%d",&b);a=b)a>b...