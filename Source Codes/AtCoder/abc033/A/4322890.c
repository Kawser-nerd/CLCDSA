main()
{
  char a[5];
  gets(a);
  int ans = 0;
  for(int i=1;i<4;i++)
  {
    ans += a[i]-a[0];
  }
  puts(ans?"DIFFERENT":"SAME");
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(a);
   ^
./Main.c:10:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(ans?"DIFFERENT":"SAME");
   ^
/tmp/cchY4Qx1.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.