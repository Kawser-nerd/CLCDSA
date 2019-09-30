int n, ans;
int main(){
  scanf("%d%d", &n);
  ans=sqrt(n);
  printf("%d\n", ans*ans);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:3:9: warning: format ‘%d’ expects a matching ‘int *’ argument [-Wformat=]
   scanf("%d%d", &n);
         ^
./Main.c:4:7: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
   ans=sqrt(n);
       ^
./Main.c:4:7: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:4:7: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:5:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ans*ans);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’