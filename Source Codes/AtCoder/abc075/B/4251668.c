#include <stdio.h>

int main(void)
{
  int h, w;
  char s[50][51];

  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; i++)
    scanf("%s", s[i]);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int count = 0;
      if (s[i][j] == '#') {
	putchar('#');
      }
      else {
	for (int a = i - 1; a <= i + 1; a++) {
	  for (int b = j - 1; b <= j + 1; b++) {
	    if (s[a][b] == '#')
	      count++;
	  }
	}
	printf("%d", count);
      }
    }
    putchar('\n');
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &h, &w);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^