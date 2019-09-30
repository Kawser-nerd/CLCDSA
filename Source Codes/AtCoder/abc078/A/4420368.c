char c;
char a, b;
int main(){
  a=getchar();
  getchar();
  b=getchar();
  if(a<b){
    c='<';
  }else if(a>b){
    c='>';
  }else{
    c='=';
  }
  putchar(c);
  putchar(10);
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   a=getchar();
     ^
./Main.c:14:3: warning: implicit declaration of function ‘putchar’ [-Wimplicit-function-declaration]
   putchar(c);
   ^