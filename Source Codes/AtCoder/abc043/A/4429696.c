int main(){
  
  int N;
  int sum = 0;
  
  scanf("%d", &N);

  for(int cnt = 1; cnt <= N; cnt++){
    sum = sum + cnt;
  }

  printf("%d\n", sum);
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &N);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", sum);
   ^
./Main.c:12:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:12:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’