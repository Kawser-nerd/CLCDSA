#include <stdio.h>
int main(int argc, char **argv)
{
  char s[1024*1024]={};
  int res[1024*1024]={};
  int n,q,l,r;
  int i;
  scanf("%d %d\n", &n, &q);
  gets(s);
  for (i=1;i<n;i++) {
    res[i] = res[i-1];
    if ((s[i]=='C') && (s[i-1]=='A')) {
      res[i]++;
    }
  }
  for (i=0;i<q;i++) {
    scanf("%d %d\n", &l, &r);
    l--;
    r--;
    printf("%d\n", res[r]-res[l]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(s);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n", &n, &q);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n", &l, &r);
     ^
/tmp/cczZ6R5F.o: In function `main':
Main.c:(.text.startup+0x5f): warning: the `gets' function is dangerous and should not be used.