int a;main(){long x,y;scanf("%ld%ld",&x,&y);while(x<=y){a++;x*=2;}printf("%d",a);} ./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 int a;main(){long x,y;scanf("%ld%ld",&x,&y);while(x<=y){a++;x*=2;}printf("%d",a);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:23: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 int a;main(){long x,y;scanf("%ld%ld",&x,&y);while(x<=y){a++;x*=2;}printf("%d",a);}
                       ^
./Main.c:1:23: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:23: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:67: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 int a;main(){long x,y;scanf("%ld%ld",&x,&y);while(x<=y){a++;x*=2;}printf("%d",a);}
                                                                   ^
./Main.c:1:67: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:67: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’