int n, a, b;
int main(){
  scanf("%d%d%d", &n, &a, &b);
  if(n*a<b){
    printf("%d\n", n*a);
  }else{
    printf("%d\n", b);
  }
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &n, &a, &b);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n", n*a);
     ^
./Main.c:5:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:7:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%d\n", b);
     ^
./Main.c:7:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’