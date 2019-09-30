int main(){
  int N,Y;
  scanf("%d %d",&N,&Y);
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N-i;j++){
      if(10000*i + 5000*j + 1000*(N-i-j) == Y){
        printf("%d %d %d",i,j,N-i-j);return 0;
      }
    }
  }
  printf("-1 -1 -1");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d %d",&N,&Y);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:9: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
         printf("%d %d %d",i,j,N-i-j);return 0;
         ^
./Main.c:7:9: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:9: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:11:3: warning: incompatible implicit declaration of built-in function ‘printf’
   printf("-1 -1 -1");
   ^
./Main.c:11:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’