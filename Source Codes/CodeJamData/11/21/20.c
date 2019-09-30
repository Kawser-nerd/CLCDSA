#include <stdio.h>

int main()
{
     int t, n, i, j, k;
     char s[100][101];

     scanf("%d", &t);

     for (i = 0; i < t; i++) {
	  int a[100][2] = {0};
	  double wp[100], owp[100], oowp[100];

	  scanf("%d", &n);

	  for (j = 0; j < n; j++) scanf("%s", s[j]);

	  for (j = 0; j < n; j++) {
	       for (k = 0; k < n; k++) {
		    if (s[j][k] == '1') {
			 a[j][0]++;
		    } else if (s[j][k] == '0') {
			 a[j][1]++;
		    }
	       }

	       wp[j] = (double)a[j][0] / (a[j][0] + a[j][1]);
	  }

	  for (j = 0; j < n; j++) {
	       int c = 0;
	       double p = 0;

	       for (k = 0; k < n; k++) {
		    if (s[j][k] != '.') {
			 c++;
			 p += (double)(a[k][0] - (s[k][j] - '0')) / (a[k][0] + a[k][1] - 1);
		    }
	       }

	       owp[j] = p / c;
	  }

	  for (j = 0; j < n; j++) {
	       int c = 0;
	       double p = 0;

	       for (k = 0; k < n; k++) {
		    if (s[j][k] != '.') {
			 c++;
			 p += owp[k];
		    }
	       }

	       oowp[j] = p / c;
	  }

	  printf("Case #%d:\n", i + 1);
	  for (j = 0; j < n; j++) {
	       printf("%lf\n", wp[j] * 0.25 + owp[j] * 0.5 + oowp[j] * 0.25);
	  }
     }

     return 0;
}
