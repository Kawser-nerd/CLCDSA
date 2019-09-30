f(a,b,u,c,d){u?d=(a^b)&u,u^=d&=-d,f(a,c=a^u&-u,u),f(c^d,b,u):printf("%d ",a);}main(n,a,b){scanf("%d%d%d",&n,&a,&b);__builtin_parity(a^b)?puts("YES"),f(a,b,(1<<n)-1):puts("NO");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 f(a,b,u,c,d){u?d=(a^b)&u,u^=d&=-d,f(a,c=a^u&-u,u),f(c^d,b,u):printf("%d ",a);}main(n,a,b){scanf("%d%d%d",&n,&a,&b);__builtin_parity(a^b)?puts("YES"),f(a,b,(1<<n)-1):puts("NO");}
 ^
./Main.c: In function ‘f’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘u’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘c’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘d’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:62: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 f(a,b,u,c,d){u?d=(a^b)&u,u^=d&=-d,f(a,c=a^u&-u,u),f(c^d,b,u):printf("%d ",a);}main(n,a,b){scanf("%d%d%d",&n,&a,&b);__builtin_parity(a^b)?puts("YES"),f(a,b,(1<<n)-1):puts("NO");}
                                                              ^
./Main.c:1:62: warning: incompatible implicit declar...