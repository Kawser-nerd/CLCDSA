#include "stdio.h"

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int tt;
	int cc[1000], ss[1000];
	double wp[1000], owp[1000], oowp[1000];
	char s[1000][1001];
	for (tt = 0; tt < tn; tt++) {
		int n;
		scanf ("%d\n", &n);
		int i, j;

		for (i = 0; i < n; i++) {
			scanf ("%s\n", s[i]); 
			//printf ("%s\n", s[i]);
			cc[i] = 0; 
			ss[i] = 0;
			for (j = 0; j < n; j++) if (s[i][j] != '.') {
				cc[i] ++;
				if (s[i][j] == '1') {
					ss[i] ++;
				}
			}         
			//printf ("%d %d\n", ss[i], cc[i]);
			wp[i] = ss[i] * 1.0 / cc[i];
		}
		for (i = 0; i < n; i++) {
			owp[i] = 0;
			for (j = 0; j < n; j++) if (s[i][j] != '.') {
				int r = 0;
				if (s[j][i] == '1') r = 1;
				owp[i] += (ss[j] - r) * 1.0 / (cc[j] - 1);
			}
			owp[i] /= cc[i];
		}
		for (i = 0; i < n; i++) {
			oowp[i] = 0;
			for (j = 0; j < n; j++) if (s[i][j] != '.') {
				oowp[i] += owp[j];
			}
			oowp[i] /= cc[i];
			//printf ("%lf %lf %lf\n", wp[i], owp[i], oowp[i]);
		}
		printf ("Case #%d:\n", tt + 1);
		for (i = 0; i < n; i++) {
			printf ("%lf\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
		}

	}
	return 0;
}
