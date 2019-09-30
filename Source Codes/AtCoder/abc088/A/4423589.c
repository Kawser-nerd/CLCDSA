char *s[]={"No", "Yes"};
int n, a;
char f;

int main(){
  scanf("%d%d", &n, &a);
  f = (n%500 <= a);
  puts(s[f]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n, &a);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[f]);
   ^