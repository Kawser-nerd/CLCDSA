main(i,n){scanf("%d",&n);printf("%d",n>104?n<135?:n<165?2:n<189?3:n<195?4:5:0);} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(i,n){scanf("%d",&n);printf("%d",n>104?n<135?:n<165?2:n<189?3:n<195?4:5:0);}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:11: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 main(i,n){scanf("%d",&n);printf("%d",n>104?n<135?:n<165?2:n<189?3:n<195?4:5:0);}
           ^
./Main.c:1:11: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:11: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:26: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 main(i,n){scanf("%d",&n);printf("%d",n>104?n<135?:n<165?2:n<189?3:n<195?4:5:0);}
                          ^
./Main.c:1:26: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:26: note: include ‘<stdio.h>’ or...