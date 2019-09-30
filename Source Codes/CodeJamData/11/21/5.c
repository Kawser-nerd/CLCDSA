#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define infile "rpi.in"
#define outfile "rpi.out"

#define N 110

char a[N][N], c;
double wp[N], oowp[N], owp[N], wp2[N];


int main()
{
	FILE *fin, *fout;
	int t, i, j, k, n, l;
	int total, won, total2;
	double sum;
	double rpi;

	fin = freopen(infile, "r", stdin);
	fout = freopen(outfile, "w", stdout);

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		memset(wp, N * sizeof(double), 0);
		memset(owp, N * sizeof(double), 0);
		memset(oowp, N * sizeof(double), 0);
		total = won = 0;

		scanf("%d\n", &n);

		for (j = 0; j < n; j++) {
			won = total = 0;
			for (k = 0; k < n; k++) {
				scanf("%c", &c);
				a[j][k] = c;
				if (c == '0') {
					total++;
				}
				else if (c == '1') {
					total++;
					won++;
				}
			}	
			
			scanf("\n");
			if (total)
				wp[j] = (won / (total * 1.0));
			//printf("wp[%d] = %.6lf, won = %d, total = %d\n", j, wp[j], won, total);
		}
		//printf("\n");

		for (j = 0; j < n; j++) {
			//printf("j = %d\n",j);
			memset(wp2, N * sizeof(double), 0);
			sum = 0; total = 0; total2 = 0;
			
			for (k = 0; k < n; k++) {
				won = total2 = 0;
				for (l = 0; l < n; l++)  {
					if (l != j) {
						if (a[k][l] == '0') {
							total2++;
						}
						else if (a[k][l] == '1') {
							total2++;
							won++;
						}
					}

				}

				if (total2)
					wp2[k] = (won / (total2 * 1.0));
				//printf("\twp2[%d] = %.6lf\n", k, wp2[k]);
			}		

			for (k = 0; k < n; k++) {
				c = a[j][k];
				if (c != '.') {
					total++;
					sum += wp2[k];
				}
			}
			if (total != 0)
				owp[j] = (sum / (total * 1.0));
		}

		for (j = 0; j < n; j++) {
			sum = 0; total = 0;
			for (k = 0; k < n; k++) {
				c = a[j][k];
				if (c != '.') {
					total++;
					sum += owp[k];
				}
			}	
			if (total) 
				oowp[j] = sum /(total * 1.0);
		}

		printf("Case #%d:\n", i+1);
		for (j = 0; j < n; j++) {
			rpi = 0.25 * wp[j] + 0.5 * owp[j] + 0.25 * oowp[j];
			printf("%.12lf\n", rpi);
		}
	}
}
