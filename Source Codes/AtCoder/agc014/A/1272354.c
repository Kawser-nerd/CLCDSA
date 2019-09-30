i=1;main(a,b,c,x){for(scanf("%d%d%d",&a,&b,&c);~a&~b&~c&1&&31&++i;x=a+b+c,a=x-a>>1,b=x-b>>1,c=x-c>>1);printf("%d",i%32-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 i=1;main(a,b,c,x){for(scanf("%d%d%d",&a,&b,&c);~a&~b&~c&1&&31&++i;x=a+b+c,a=x-a>>1,b=x-b>>1,c=x-c>>1);printf("%d",i%32-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i=1;main(a,b,c,x){for(scanf("%d%d%d",&a,&b,&c);~a&~b&~c&1&&31&++i;x=a+b+c,a=x-a>>1,b=x-b>>1,c=x-c>>1);printf("%d",i%32-1);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:23: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i=1;main(a,b,c,x){for(scanf("%d%d%d",&a,&b,&c);~a&~b&~c&1&&31&++i;x=a+b+c,a=x-a>>1,b=x-b>>1,c=x-c>>1);printf("%d",i%32-1);}
       ...