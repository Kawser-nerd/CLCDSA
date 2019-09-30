char s[11];
int main(){
  scanf("%s", s);
  s[3]='8';
  printf("%s", s);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s", s);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%s", s);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’