main(){int a,b;scanf("%d %d",&a,&b);puts(a%3&&b%3&&(a+b)%3?"Impossible":"Possible");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){int a,b;scanf("%d %d",&a,&b);puts(a%3&&b%3&&(a+b)%3?"Impossible":"Possible");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:16: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(){int a,b;scanf("%d %d",&a,&b);puts(a%3&&b%3&&(a+b)%3?"Impossible":"Possible");}
                ^
./Main.c:1:16: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:16: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:37: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(){int a,b;scanf("%d %d",&a,&b);puts(a%3&&b%3&&(a+b)%3?"Impossible":"Possible");}
                                     ^