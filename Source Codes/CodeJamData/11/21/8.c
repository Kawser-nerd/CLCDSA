#include <stdio.h>

char s[110][110];
int win[110], all[110];
double wp[110], owp[110], oowp[110];

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int n, i, j;
		scanf("%d\n", &n);
		for (i = 0; i < n; i++) {
			gets(s[i]);
		}
		for (i = 0; i < n; i++) {
			all[i] = win[i] = 0;
			for (j = 0; j < n; j++) {
				if (s[i][j] != '.') all[i]++;
				if (s[i][j] == '1') win[i]++;
			}
			wp[i] = (double)win[i]/(double)all[i];
		}
		for (i = 0; i < n; i++) {
			owp[i] = 0;
			for (j = 0; j < n; j++) {
				if (s[i][j] != '.') owp[i] += (double)(win[j]-(s[j][i] == '1' ? 1 : 0))/(double)(all[j]-1);
			}
			owp[i] /= (double)all[i];
		}
		for (i = 0; i < n; i++) {
			oowp[i] = 0;
			for (j = 0; j < n; j++) {
				if (s[i][j] != '.') oowp[i] += owp[j];
			}
			oowp[i] /= (double)all[i];
		}
		printf("Case #%d:\n", ti);
		for (i = 0; i < n; i++) {
			printf("%.8lf\n", 0.25*wp[i]+0.5*owp[i]+0.25*oowp[i]);
		}
	}
	return 0;
}
