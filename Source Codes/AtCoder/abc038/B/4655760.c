main(h,w,i,x){scanf("%d%d%d%d",&h,&w,&i,&x);puts(h!=i&h!=x&w!=i&w!=x?"NO":"YES");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(h,w,i,x){scanf("%d%d%d%d",&h,&w,&i,&x);puts(h!=i&h!=x&w!=i&w!=x?"NO":"YES");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘h’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘x’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:15: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(h,w,i,x){scanf("%d%d%d%d",&h,&w,&i,&x);puts(h!=i&h!=x&w!=i&w!=x?"NO":"YES");}
               ^
./Main.c:1:15: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:15: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:45: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(h,w,i,x){scanf("%d%d%d%d",&h,&w,&i,&x);puts(h!=i&h!=x&w!=i&w!=x?"NO":"YES");}
           ...