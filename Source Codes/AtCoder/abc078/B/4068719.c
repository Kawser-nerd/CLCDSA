main(x,y,z){scanf("%d%d%d",&x,&y,&z);printf("%d\n",(x-z)/(y+z));} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(x,y,z){scanf("%d%d%d",&x,&y,&z);printf("%d\n",(x-z)/(y+z));}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘y’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘z’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:13: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(x,y,z){scanf("%d%d%d",&x,&y,&z);printf("%d\n",(x-z)/(y+z));}
             ^
./Main.c:1:13: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:13: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:38: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(x,y,z){scanf("%d%d%d",&x,&y,&z);printf("%d\n",(x-z)/(y+z));}
                                      ^
./Main.c:1:38: warning: incompatible implicit declaration of built-in function ‘printf’
./Ma...