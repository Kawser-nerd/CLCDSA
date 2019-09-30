a,b;main(n){scanf("%d%d%d",&n,&a,&b);puts(n<=a||a==b&&n%-~a||a>b?"Takahashi":"Aoki");} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b;main(n){scanf("%d%d%d",&n,&a,&b);puts(n<=a||a==b&&n%-~a||a>b?"Takahashi":"Aoki");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b;main(n){scanf("%d%d%d",&n,&a,&b);puts(n<=a||a==b&&n%-~a||a>b?"Takahashi":"Aoki");}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b;main(n){scanf("%d%d%d",&n,&a,&b);puts(n<=a||a==b&&n%-~a||a>b?"Takahashi":"Aoki");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a,b;main(n){scanf("%d%d%d",&n,&a,&b);puts(n<=a||a==b&&n%-~a||a>b?"Takahashi":"Aoki");}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or prov...