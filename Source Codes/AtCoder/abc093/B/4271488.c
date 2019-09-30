i;main(a,b,k){scanf("%d%d%d",&a,&b,&k);for(i=a;i<=b;i++)if(i<a+k||i>b-k)printf("%d\n",i);} ./Main.c:1:1: warning: data definition has no type or storage class
 i;main(a,b,k){scanf("%d%d%d",&a,&b,&k);for(i=a;i<=b;i++)if(i<a+k||i>b-k)printf("%d\n",i);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i;main(a,b,k){scanf("%d%d%d",&a,&b,&k);for(i=a;i<=b;i++)if(i<a+k||i>b-k)printf("%d\n",i);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:3: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:3: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i;main(a,b,k){scanf("%d%d%d",&a,&b,&k);for(i=a;i<=b;i++)if(i<a+k||i>b-k)printf("%d\n",i);}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scan...