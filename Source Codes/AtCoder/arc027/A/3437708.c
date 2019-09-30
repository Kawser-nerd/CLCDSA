main(h,m){scanf("%d%d",&h,&m);printf("%d\n",1080-h*60-m);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(h,m){scanf("%d%d",&h,&m);printf("%d\n",1080-h*60-m);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘h’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘m’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(h,m){scanf("%d%d",&h,&m);printf("%d\n",1080-h*60-m);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:31: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(h,m){scanf("%d%d",&h,&m);printf("%d\n",1080-h*60-m);}
                               ^
./Main.c:1:31: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:31: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’