a;main(){scanf("%d",&a);printf("%d",a/3);} ./Main.c:1:1: warning: data definition has no type or storage class
 a;main(){scanf("%d",&a);printf("%d",a/3);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a;main(){scanf("%d",&a);printf("%d",a/3);}
   ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a;main(){scanf("%d",&a);printf("%d",a/3);}
          ^
./Main.c:1:10: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:10: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:25: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 a;main(){scanf("%d",&a);printf("%d",a/3);}
                         ^
./Main.c:1:25: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:25: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’