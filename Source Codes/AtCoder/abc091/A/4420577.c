char *s[]={"No","Yes"};
int a, b, c;
char f;
int main(){
  scanf("%d%d%d", &a, &b, &c);
  f=a+b>=c;
  puts(s[f]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &a, &b, &c);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[f]);
   ^