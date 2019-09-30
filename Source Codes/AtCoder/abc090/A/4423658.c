char c[3];
int main(){
  c[0]=getchar();
  getchar();
  getchar();
  getchar();
  getchar();
  c[1]=getchar();
  getchar();
  getchar();
  getchar();
  getchar();
  c[2]=getchar();
  putchar(c[0]);
  putchar(c[1]);
  putchar(c[2]);
  putchar(10);
} ./Main.c: In function ‘main’:
./Main.c:3:8: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   c[0]=getchar();
        ^
./Main.c:14:3: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
   putchar(c[0]);
   ^