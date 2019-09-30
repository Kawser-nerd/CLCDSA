int main(){
  int N,a,t,s=0;
  scanf("%d",&N);
  while(N--){
    scanf("%d",&a);
    asm volatile(
      "bsf %0,%1":"=r"(t):"r"(a)
    );
    s+=t;
  }
  printf("%d\n",s);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d",&N);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:11:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n",s);
   ^
./Main.c:11:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:11:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’