#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
     double a, b, c;
     double delta;
     int T, ncase;
     long long t, r;
     long long foo;
     long long nblk;
     
     
     scanf("%d", &T);
     for (ncase = 1; ncase <= T; ncase++) {
	  scanf("%lld%lld", &r, &t);
	  a = 2;
	  b = 2 * r + 3;
	  c = 2 * r + 1 - t;
	  if (b*b - 4*a*c < 0) {
	       printf("delta < 0!\n");
	       exit(1);
	  }
	  delta = sqrt(b*b-4*a*c);
	  /* printf("%lf\n", delta); */
	  nblk = (-b + delta) / (2 * a);
	  while ((foo=2*nblk*nblk+(2*r+3)*nblk+2*r+1-t) > 0)
	       nblk--;
	  while ((foo=2*nblk*nblk+(2*r+3)*nblk+2*r+1-t) <= 0)
	       nblk++;	  
	  printf("Case #%d: %lld\n", ncase, nblk);
     }

     return 0;
}
     
