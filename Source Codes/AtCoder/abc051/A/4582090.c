main(i,a)char*a;{scanf("%s",a);a[5]=a[13]=' ';puts(a);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,a)char*a;{scanf("%s",a);a[5]=a[13]=' ';puts(a);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(i,a)char*a;{scanf("%s",a);a[5]=a[13]=' ';puts(a);}
                  ^
./Main.c:1:18: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:18: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:47: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(i,a)char*a;{scanf("%s",a);a[5]=a[13]=' ';puts(a);}
                                               ^