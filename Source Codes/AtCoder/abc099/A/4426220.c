int n;
int main(){
  scanf("%d", &n);
  if(n<=999){
    puts("ABC");
  }else{
    puts("ABD");
  }
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &n);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:5: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
     puts("ABC");
     ^