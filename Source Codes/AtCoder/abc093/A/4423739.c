char *s[]={"No","Yes"};
char a;
int main(){
  a=1<<(getchar()-'a')*2;
  a+=1<<(getchar()-'a')*2;
  a+=1<<(getchar()-'a')*2;
  puts(s[a==21]);
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   a=1<<(getchar()-'a')*2;
         ^
./Main.c:7:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[a==21]);
   ^