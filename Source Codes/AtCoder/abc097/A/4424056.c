int dif(int a, int b){return a<b?b-a:a-b;}
char *s[]={"No","Yes"};
int a, b, c, d;
char f;
int main(){
  scanf("%d%d%d%d", &a, &b, &c, &d);
  f = dif(a,c)<=d || (dif(a,b)<=d && dif(c,b)<=d);
  puts(s[f]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[f]);
   ^