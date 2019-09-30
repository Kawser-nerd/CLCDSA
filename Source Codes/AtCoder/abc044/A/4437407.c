int main(){
  
  int N, K, X, Y;
  int sum = 0;
  
  scanf("%d%d%d%d", &N, &K, &X, &Y);

  for(int cnt = 1; cnt <= N; cnt++){
    if(cnt <= K){
      sum = sum + X;
    }else{
      sum = sum + Y;
    }
  }

  printf("%d\n", sum);
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d", &N, &K, &X, &Y);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:16:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", sum);
   ^
./Main.c:16:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:16:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’