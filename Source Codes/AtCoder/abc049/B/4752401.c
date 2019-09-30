#include <stdio.h>

int main()
{
  int H,W;
  scanf("%d %d", &H, &W);
  char c[100][100];
  for(int i=0;i<H;i++){
    scanf("%s", &c[i]);
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      printf("%c", c[i][j]);
    }
    putchar('\n');
    for(int j=0;j<W;j++){
      printf("%c", c[i][j]);
    }
    putchar('\n');
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
     scanf("%s", &c[i]);
           ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", &c[i]);
     ^