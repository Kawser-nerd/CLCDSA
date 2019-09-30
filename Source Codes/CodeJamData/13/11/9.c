#include <stdio.h>

int main ()
{
  int T, i;
  long long r, t, l, h,y;
  scanf ("%d", &T); 
  for (i = 1; i <= T; i++) {
    scanf ("%lld%lld", &r, &t);
    for (y = 0; t >= r + r + 1; r += 2, y++) t -= r + r + 1;
    /*for (l = 0, h = 2000000; l + 1 < h; ) {
      if (t <= (2*r+1 + 2*(r + (l+h)/2-1) + 1)*((l+h)/2)/2) l = (l+h)/2;
      else h = (l + h) / 2;
    }*/
    printf ("Case #%d: %d\n", i, y);
  }
  return 0;
}
