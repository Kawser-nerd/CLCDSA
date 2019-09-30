int n, a, ans, i;
int main(){
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a);
    while((a&1)==0){ans++;a>>=1;}
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &n);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:8:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ans);
   ^
./Main.c:8:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:8:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’