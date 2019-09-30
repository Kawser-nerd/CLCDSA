i=3;main(n,j){scanf("%d",&n);if(n==3)printf("2 3 25\n");else{for(;j=(n-i+((n-i)%2)),!(0<j&&j<5001&&i<15001);i+=3);for(i-=(n-i)%2;i--;)printf("%d ",2*i+2);for(;j;)printf("%d%s",6*j+3,--j?" ":"\n");}return 0;} ./Main.c:1:1: warning: data definition has no type or storage class
 i=3;main(n,j){scanf("%d",&n);if(n==3)printf("2 3 25\n");else{for(;j=(n-i+((n-i)%2)),!(0<j&&j<5001&&i<15001);i+=3);for(i-=(n-i)%2;i--;)printf("%d ",2*i+2);for(;j;)printf("%d%s",6*j+3,--j?" ":"\n");}return 0;}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i=3;main(n,j){scanf("%d",&n);if(n==3)printf("2 3 25\n");else{for(;j=(n-i+((n-i)%2)),!(0<j&&j<5001&&i<15001);i+=3);for(i-=(n-i)%2;i--;)printf("%d ",2*i+2);for(;j;)printf("%d%s",6*j+3,--j?" ":"\n");}return 0;}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:5: warning: type of ‘j’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 i=3;main(n,j){scanf("%d",&n);if(n==3)printf("2 3 25\n");else{for(;j=(n-i+((n-i)%2)),!(0<j&&j<5001&&i<15...