char *s[]={"NO","YES"};
int a, b, x;
char f;
int main(){
  scanf("%d%d%d\n", &a, &b, &x);
  f = (x>=a && x<=a+b);
  puts(s[f]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d\n", &a, &b, &x);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[f]);
   ^