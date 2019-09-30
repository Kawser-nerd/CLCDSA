n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));} ./Main.c:1:1: warning: data definition has no type or storage class
 n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:3: warning: return type defaults to ‘int’ [-Wimplicit-int]
 n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));}
   ^
./Main.c: In function ‘main’:
./Main.c:1:10: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));}
          ^
./Main.c:1:19: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));}
                   ^
./Main.c:1:19: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:1:19: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:1:32: warning: implicit declaration of function ‘pow’ [-Wimplicit-function-declaration]
 n;main(){gets(&n);printf("%.f",pow(atoi(&n),.25));}
    ...