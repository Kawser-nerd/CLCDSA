a[11];main(){scanf("%s",a);printf("%spp\n",a);} ./Main.c:1:1: warning: data definition has no type or storage class
 a[11];main(){scanf("%s",a);printf("%spp\n",a);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 a[11];main(){scanf("%s",a);printf("%spp\n",a);}
       ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 a[11];main(){scanf("%s",a);printf("%spp\n",a);}
              ^
./Main.c:1:14: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:14: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:1:20: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
 a[11];main(){scanf("%s",a);printf("%spp\n",a);}
                    ^
./Main.c:1:28: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
 a[11];main(){scanf("%s",a);printf("%spp\n",a);...