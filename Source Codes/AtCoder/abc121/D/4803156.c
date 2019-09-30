main(){
  long n,m,r;
  scanf("%ld%ld",&n,&m);
  r=n%2?n++:0;
  r^=m%2?0:m--;
  printf("%ld",(m-n+1)%4?r^1:r);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%ld%ld",&n,&m);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%ld",(m-n+1)%4?r^1:r);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’