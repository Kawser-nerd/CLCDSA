int a, b, t, max;
int main(){
  scanf("%d%d", &a, &b);
  max=a+b;
  t=a-b;
  if(t>max) max=t;
  t=a*b;
  if(t>max) max=t;
  printf("%d\n", max);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &a, &b);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:9:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", max);
   ^
./Main.c:9:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:9:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’