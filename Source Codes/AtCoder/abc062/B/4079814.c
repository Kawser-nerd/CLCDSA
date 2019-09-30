#include <stdio.h>
#include <string.h>
int main()
{
  int H, W, i, j;
  scanf("%d %d%*c", &H, &W);
  char arr[H+2][W+1];
  for (i=0; i<H+2; i++) {
    char str[102];
    if (i==0 || i==H+1) {
      for (j=0; j<W; j++) {
        str[j] = '#';
      }
      str[j] = '\0';
      strcpy(arr[i], str);
    } else {
      scanf("%s%*c", arr[i]);
    }
  }
  for (i=0; i<H+2; i++) {
    printf("#%s#\n", arr[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d%*c", &H, &W);
   ^
./Main.c:17:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s%*c", arr[i]);
       ^