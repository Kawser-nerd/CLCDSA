#include <stdio.h>

int main()
{
     int t, n, l, h, i, j, k;
     int a[100];

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int f = 0;

	  scanf("%d %d %d", &n, &l, &h);

	  for (j = 0; j < n; j++) scanf("%d", &a[j]);

	  for (j = l; j <= h; j++) {
	       for (k = 0; k < n; k++) {
		    if (j % a[k] != 0 && a[k] % j != 0) {
			 break;
		    }
	       }

	       if (k == n) {
		    printf("Case #%d: %d\n", i + 1, j);
		    f = 1;
		    break;
	       }
	  }

	  if (f == 0) {
	       printf("Case #%d: NO\n", i + 1);
	  }
     }

     return 0;
}
