main(h,w){scanf("%d%d",&h,&w)<printf("%.f",h%3&&w%3?h&w&1?h-w?h<w?h:w:~h/6+h:fmin(h%2?h:h/2,w%2?w:w/2):0);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(h,w){scanf("%d%d",&h,&w)<printf("%.f",h%3&&w%3?h&w&1?h-w?h<w?h:w:~h/6+h:fmin(h%2?h:h/2,w%2?w:w/2):0);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘h’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘w’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(h,w){scanf("%d%d",&h,&w)<printf("%.f",h%3&&w%3?h&w&1?h-w?h<w?h:w:~h/6+h:fmin(h%2?h:h/2,w%2?w:w/2):0);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:31: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(h,w){scanf("%d%d",&h,&w)<printf("%.f",h%3&&w%3?h&w&1?h-w?h<w?h:w:~h/6+h:fmin(h%2?h:h/2,w%2?w:w/2):0);}
                               ^
./Main.c:1:31: warning: incompatible implicit...