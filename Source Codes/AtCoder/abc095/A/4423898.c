char *s[]={"700","800","900","1000"};
char a;
int main(){
  if(getchar()=='o')a++;
  if(getchar()=='o')a++;
  if(getchar()=='o')a++;
  puts(s[a]);
} ./Main.c: In function ‘main’:
./Main.c:4:6: warning: implicit declaration of function ‘getchar’ [-Wimplicit-function-declaration]
   if(getchar()=='o')a++;
      ^
./Main.c:7:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(s[a]);
   ^