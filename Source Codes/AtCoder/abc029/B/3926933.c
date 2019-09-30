#include<stdio.h>
#include<string.h>
char srx[11];
int sry,i,j;
int main()
{
  for(i=1;i<=12;++i)
  {gets(srx);
  int n=strlen(srx);
  for(j=0;j<n;++j)
  if(srx[j]=='r')
  {sry++;
  break;}}
  printf("%d\n",sry);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:4: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   {gets(srx);
    ^
/tmp/ccBfRnbt.o: In function `main':
Main.c:(.text.startup+0x18): warning: the `gets' function is dangerous and should not be used.