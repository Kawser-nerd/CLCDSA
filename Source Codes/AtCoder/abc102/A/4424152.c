int n;
int main(){
  scanf("%d", &n);
  printf("%d\n", n<<(n&1));
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &n);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:4:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", n<<(n&1));
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’