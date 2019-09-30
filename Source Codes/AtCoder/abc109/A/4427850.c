char *S[]={"No","Yes"};
char f;

int a, b;
int main(){
  scanf("%d%d", &a, &b);
  f = a*b&1;
  puts(S[f]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &a, &b);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(S[f]);
   ^