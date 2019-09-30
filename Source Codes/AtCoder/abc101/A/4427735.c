int a;
int main(){
  if(getchar()=='+'){a++;}else{a--;}
  if(getchar()=='+'){a++;}else{a--;}
  if(getchar()=='+'){a++;}else{a--;}
  if(getchar()=='+'){a++;}else{a--;}
  printf("%d\n", a);
} ./Main.c: In function ‘main’:
./Main.c:3:6: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   if(getchar()=='+'){a++;}else{a--;}
      ^
./Main.c:7:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", a);
   ^
./Main.c:7:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’