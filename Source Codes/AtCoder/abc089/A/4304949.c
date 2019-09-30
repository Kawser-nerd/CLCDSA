a;
main(){
  scanf("%d",&a);
  printf("%d",a/3);
} ./Main.c:1:1: warning: data definition has no type or storage class
 a;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d",&a);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:4:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d",a/3);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’