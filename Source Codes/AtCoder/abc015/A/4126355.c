main(){
  char a[99],b[99];gets(a);gets(b);
  int i=0;
  while(a[i]&&b[i])i++;
  puts(a[i]?a:b);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:2:20: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   char a[99],b[99];gets(a);gets(b);
                    ^
./Main.c:5:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(a[i]?a:b);
   ^
/tmp/ccVDDN6p.o: In function `main':
Main.c:(.text.startup+0x1e): warning: the `gets' function is dangerous and should not be used.