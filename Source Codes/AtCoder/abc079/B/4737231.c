long m[99];long l(n){return m[n]?:n?n-1?m[n]=l(n-1)+l(n-2):1:2;}main(n){scanf("%d",&n);printf("%ld",l(n));} ./Main.c: In function ‘l’:
./Main.c:1:17: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 long m[99];long l(n){return m[n]?:n?n-1?m[n]=l(n-1)+l(n-2):1:2;}main(n){scanf("%d",&n);printf("%ld",l(n));}
                 ^
./Main.c: At top level:
./Main.c:1:65: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long m[99];long l(n){return m[n]?:n?n-1?m[n]=l(n-1)+l(n-2):1:2;}main(n){scanf("%d",&n);printf("%ld",l(n));}
                                                                 ^
./Main.c: In function ‘main’:
./Main.c:1:65: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:73: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long m[99];long l(n){return m[n]?:n?n-1?m[n]=l(n-1)+l(n-2):1:2;}main(n){scanf("%d",&n);printf("%ld",l(n));}
                                                                         ^
./Main.c:1:73: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:73: note: include ‘<stdio.h>’ or provide a de...