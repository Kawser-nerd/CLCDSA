main(w,a,b){scanf("%d%d%d",&w,&a,&b);printf("%.f",fmax(b-a-w,fmax(a-b-w,0)));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(w,a,b){scanf("%d%d%d",&w,&a,&b);printf("%.f",fmax(b-a-w,fmax(a-b-w,0)));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(w,a,b){scanf("%d%d%d",&w,&a,&b);printf("%.f",fmax(b-a-w,fmax(a-b-w,0)));}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(w,a,b){scanf("%d%d%d",&w,&a,&b);printf("%.f",fmax(b-a-w,fmax(a-b-w,0)));}
                                      ^
./Main.c:1:38: warning: incompatible implicit declara...