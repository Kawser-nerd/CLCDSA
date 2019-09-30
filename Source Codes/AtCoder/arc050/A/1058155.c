a,b;main(){scanf("%c %c",&a,&b);puts(a-b+32?"No":"Yes");} ./Main.c:1:1: warning: data definition has no type or storage class
 a,b;main(){scanf("%c %c",&a,&b);puts(a-b+32?"No":"Yes");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a,b;main(){scanf("%c %c",&a,&b);puts(a-b+32?"No":"Yes");}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a,b;main(){scanf("%c %c",&a,&b);puts(a-b+32?"No":"Yes");}
     ^
./Main.c: In function ‘main’:
./Main.c:1:12: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a,b;main(){scanf("%c %c",&a,&b);puts(a-b+32?"No":"Yes");}
            ^
./Main.c:1:12: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:12: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:18: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
 a,b;main(){scanf("%c %c",&a,&b);puts(a-b+3...