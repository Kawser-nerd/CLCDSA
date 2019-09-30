char c, d;
int main(){
  c=getchar();
  while(c!=10&&d!=10){
    putchar(c);
    d=getchar();
    c=getchar();
  }
  putchar(10);
} ./Main.c: In function ‘main’:
./Main.c:3:5: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   c=getchar();
     ^
./Main.c:5:5: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
     putchar(c);
     ^