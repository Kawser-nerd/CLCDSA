int min(int a, int b){return a>b?b:a;}
int a, b, c, d;
int main(){
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf("%d\n", min(a,b)+min(c,d));
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", min(a,b)+min(c,d));
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’