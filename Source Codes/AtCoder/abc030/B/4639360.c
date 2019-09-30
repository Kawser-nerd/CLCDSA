main(n,m,a){scanf("%d%d",&n,&m);printf("%f\n",fmin(720-a,a=abs(60*n-11*m)%720)/2);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n,m,a){scanf("%d%d",&n,&m);printf("%f\n",fmin(720-a,a=abs(60*n-11*m)%720)/2);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(n,m,a){scanf("%d%d",&n,&m);printf("%f\n",fmin(720-a,a=abs(60*n-11*m)%720)/2);}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:33: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(n,m,a){scanf("%d%d",&n,&m);printf("%f\n",fmin(720-a,a=abs(60*n-11*m)%720)/2);}
                                 ^
./Main.c:1:33: warning: incompatible implic...