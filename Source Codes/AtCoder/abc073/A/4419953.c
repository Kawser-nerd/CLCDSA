char c[2];
int main(){
  c[0]=getchar();
  c[1]=getchar();
  if(c[0]=='9' || c[1]=='9'){
    puts("Yes");
  }else{
    puts("No");
  }
} ./Main.c: In function ‘main’:
./Main.c:3:8: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   c[0]=getchar();
        ^
./Main.c:6:5: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
     puts("Yes");
     ^