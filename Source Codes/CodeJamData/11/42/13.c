#include <stdio.h>

int main()
{
     int t, r, c, d, i, j, k, l, m, n;

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int max = 0;
	  char s[500][501];

	  scanf("%d %d %d", &r, &c, &d);

	  for (j = 0; j < r; j++) scanf("%s", s[j]);

	  for (j = 1; j < r - 1; j++) {
	       for (k = 1; k < c - 1; k++) {
		    int min = j;
		    if (k < min) min = k;
		    if (r - j - 1 < min) min = r - j - 1;
		    if (c - k - 1 < min) min = c - k - 1;

		    for (l = 1; l <= min; l++) {
			 int a = 0, b = 0, c = 0, d = 0;
			 int x1, x2, x3, x4;

			 x1 = (s[j - l][k - l] - '0') * l;
			 x2 = (s[j - l][k + l] - '0') * l;
			 x3 = (s[j + l][k - l] - '0') * l;
			 x4 = (s[j + l][k + l] - '0') * l;

			 for (m = j - l; m <= j + l; m++) {
			      for (n = k - l; n <= k + l; n++) {
				   if (m < j) a += (s[m][n] - '0') * (j - m);
				   if (m > j) b += (s[m][n] - '0') * (m - j);
				   if (n < k) c += (s[m][n] - '0') * (k - n);
				   if (n > k) d += (s[m][n] - '0') * (n - k);
			      }
			 }

			 a -= x1 + x2;
			 b -= x3 + x4;
			 c -= x1 + x3;
			 d -= x2 + x4;

			 if (a == b && c == d) {
			      if (2 * l + 1 > max) max = 2 * l + 1;
			 }
		    }
	       }
	  }

	  for (j = 0; j < r; j++) {
	       for (k = 0; k < r; k++) {
		    int min = r - j;
		    if (c - k< min) min = c - k;

		    if (max == 0) {
			 l = 4;
		    } else {
			 l = max + 1;
		    }

		    for (l = 4; l <= min; l += 2) {
			 double a = 0, b = 0, c = 0, d = 0;
			 double x1, x2, x3, x4;

			 x1 = (s[j][k] - '0') * (l / 2 - 0.5);
			 x2 = (s[j][k + l - 1] - '0') * (l / 2 - 0.5);
			 x3 = (s[j + l - 1][k] - '0') * (l / 2 - 0.5);
			 x4 = (s[j + l - 1][k + l - 1] - '0') * (l / 2 - 0.5);

			 for (m = j; m < j + l; m++) {
			      for (n = k; n < k + l; n++) {
				   if (m < j + l / 2) {
					a += (s[m][n] - '0') * (j + l / 2 - m - 0.5);
				   } else {
					b += (s[m][n] - '0') * (m - j - l / 2 + 0.5);
				   }
				   if (n < k + l / 2) {
					c += (s[m][n] - '0') * (k + l / 2 - n - 0.5);
				   } else {
					d += (s[m][n] - '0') * (n - k - l / 2 + 0.5);
				   }
			      }
			 }

			 a -= x1 + x2;
			 b -= x3 + x4;
			 c -= x1 + x3;
			 d -= x2 + x4;

			 if (a == b && c == d) {
			      if (l > max) max = l;
			 }
		    }
	       }
	  }

	  if (max == 0) {
	       printf("Case #%d: IMPOSSIBLE\n", i + 1);
	  } else {
	       printf("Case #%d: %d\n", i + 1, max);
	  }
     }

     return 0;
}
