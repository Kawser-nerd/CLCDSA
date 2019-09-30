char c;
int A, B, C, D, a, b;
char *s[]={"Right","Left","Balanced"};
int main(){
  scanf("%d%d%d%d", &A, &B, &C, &D);
  a=A+B;
  b=C+D;
  if(a<b){
    c=0;
  }else if(a>b){
    c=1;
  }else{
    c=2;
  }
  puts(s[c]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d", &A, &B, &C, &D);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:15:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[c]);
   ^