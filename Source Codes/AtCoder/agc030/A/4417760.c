int a, b, c;

int main(){
  scanf("%d%d%d", &a, &b, &c);
  if(a+b+1>=c){
    printf("%d\n", b+c);
  }else{
    printf("%d\n", a+b+b+1);
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &a, &b, &c);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n", b+c);
     ^
./Main.c:6:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:8:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%d\n", a+b+b+1);
     ^
./Main.c:8:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’