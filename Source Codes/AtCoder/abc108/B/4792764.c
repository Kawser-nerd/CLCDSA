main(x,y,z,w){scanf("%d%d%d%d",&x,&y,&z,&w);printf("%d %d %d %d",z-w+y,w+z-x,x+y-w,y-x+z);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(x,y,z,w){scanf("%d%d%d%d",&x,&y,&z,&w);printf("%d %d %d %d",z-w+y,w+z-x,x+y-w,y-x+z);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘y’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘z’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(x,y,z,w){scanf("%d%d%d%d",&x,&y,&z,&w);printf("%d %d %d %d",z-w+y,w+z-x,x+y-w,y-x+z);}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:45: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(x,y,z,w){scanf("%d%d%d%d",&x,&y,&z,&w);printf("%d %d %d %d",z-w+y,w+z...