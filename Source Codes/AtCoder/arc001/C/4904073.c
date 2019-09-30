main(a,b){scanf("%d%d",&a,&b);b=abs(a-b),a=b/5+1,printf("%.f\n",fmin(a/2+b%5,-~a/2+5-b%5));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a,b){scanf("%d%d",&a,&b);b=abs(a-b),a=b/5+1,printf("%.f\n",fmin(a/2+b%5,-~a/2+5-b%5));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);b=abs(a-b),a=b/5+1,printf("%.f\n",fmin(a/2+b%5,-~a/2+5-b%5));}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:33: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
 main(a,b){scanf("%d%d",&a,&b);b=abs(a-b),a=b/5+1,printf("%.f\n",fmin(a/2+b%5,-~a/2+5-b%5));}
                                 ^
./Main.c:1:50: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-decl...