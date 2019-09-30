#include <stdio.h>

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Case #%d: ", t);
    for (; x > 0; x--)
      printf("WE");
    for (; x < 0; x++)
      printf("EW");
    for (; y > 0; y--)
      printf("SN");
    for (; y < 0; y++)
      printf("NS");
    printf("\n");
  }
  return 0;
}