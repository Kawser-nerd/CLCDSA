char *s[]={":(","Yay!"};
int a, b;
char f;
int main(){
  scanf("%d%d", &a, &b);
  f = a<=8 && b<=8;
  puts(s[f]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &a, &b);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[f]);
   ^