main(n,a,b){scanf("%d%d%d",&n,&a,&b);printf("%d\n",((n>4)*5+(n<5)*n)*b+(n>4)*(n-5)*a);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,a,b){scanf("%d%d%d",&n,&a,&b);printf("%d\n",((n>4)*5+(n<5)*n)*b+(n>4)*(n-5)*a);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(n,a,b){scanf("%d%d%d",&n,&a,&b);printf("%d\n",((n>4)*5+(n<5)*n)*b+(n>4)*(n-5)*a);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(n,a,b){scanf("%d%d%d",&n,&a,&b);printf("%d\n",((n>4)*5+(n<5)*n)*b+(n>4)*(n-5)*a);}
                                      ^
./Main.c:1:38: warning: in...