#include <stdio.h>
#include <inttypes.h>

int32_t n, m;
int32_t a[1000000];

int64_t imos[1000000];
int64_t ruiseki_minus[1000000];

int main(void) {
	int32_t i;
	int64_t honrai = 0;
	int64_t max_sakugen = 0;
	int64_t current_honrai;
	if (scanf("%"SCNd32"%"SCNd32, &n, &m) != 2) return 1;
	for (i = 0; i < n; i++) {
		if (scanf("%"SCNd32, &a[i]) != 1) return 1;
	}
	/* ??? */
	for (i = 1; i < n; i++) {
		if (a[i - 1] < a[i]) {
			honrai += (current_honrai = a[i] - a[i - 1]);
			if (a[i - 1] + 2 <= a[i]) {
				imos[a[i - 1] + 2]++;
				imos[a[i] + 1]--;
				ruiseki_minus[a[i] + 1] += current_honrai - 1;
			}
		} else {
			honrai += (current_honrai = a[i] + (m - a[i - 1]));
			if (a[i - 1] + 2 <= m) {
				imos[a[i - 1] + 2]++;
				imos[m + 1]--;
				imos[1] += m - a[i - 1];
				imos[2] -= m - a[i - 1];
				imos[2]++;
				imos[a[i] + 1]--;
			} else if (a[i - 1] == m - 1) {
				imos[1]++;
				imos[a[i] + 1]--;
			} else { /* a[i - 1] == m */
				imos[2]++;
				imos[a[i] + 1]--;
			}
			ruiseki_minus[a[i] + 1] += current_honrai - 1;
		}
	}
	/* ??????? */
	for (i = 1; i <= m; i++) imos[i] += imos[i - 1];
	for (i = 1; i <= m; i++) imos[i] += imos[i - 1] - ruiseki_minus[i];
	/* ?? */
	for (i = 1; i <= m; i++) {
		if (imos[i] > max_sakugen) max_sakugen = imos[i];
	}
	printf("%"PRId64"\n", honrai - max_sakugen);
	return 0;
}

/*
??????????
???
* * * s * * d * *
0 0 0 0 0 1 1 0 0
0 0 0 0 0 1 2 0 0

* * * d * s * * *
3 1 1 1 0 0 0 1 1
3 4 5 6 0 0 0 1 2

* * * d * * * s *
1 1 1 1 0 0 0 0 0
1 2 3 4 0 0 0 0 0

* * * d * * * * s
0 1 1 1 0 0 0 0 0
0 1 2 3 0 0 0 0 0

* * * d s * * * *
4 1 1 1 0 0 1 1 1
4 5 6 7 0 0 1 2 3
*/