int main(void)
{
  char a[3],b[3];
  gets(a);
  gets(b);
  if(a[0]==b[2] && a[1]==b[1] && a[2]==b[0])
  {
    puts("YES");
  }
  else
  {
    puts("NO");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(a);
   ^
./Main.c:8:5: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
     puts("YES");
     ^
/tmp/cczCEDv5.o: In function `main':
Main.c:(.text.startup+0xa): warning: the `gets' function is dangerous and should not be used.