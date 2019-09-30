int main(){
  
  int a, b, h;
  
  scanf("%d%d%d", &a, &b, &h);

  printf("%d\n", ((a + b) * h) /2 );
  
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &a, &b, &h);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ((a + b) * h) /2 );
   ^
./Main.c:7:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’