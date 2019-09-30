int X, t;

int main(){
  scanf("%d%d", &X, &t);
  if(X>t){
    printf("%d\n", X-t);
  }else{
    puts("0");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &X, &t);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n", X-t);
     ^
./Main.c:6:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:8:5: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
     puts("0");
     ^