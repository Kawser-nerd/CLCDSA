#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000000000000LL

long long minabs, mincn, minjn;
char minc[19], minj[19];

int less(long long cn, long long jn) {
	if (llabs(cn - jn) == minabs)
		if (cn == mincn)
			return jn < minjn;
		else
			return cn < mincn;
	else
		return llabs(cn - jn) < minabs;
}

void check_and_set(const char *c, const char *j) {
	const long long cn = atoll(c), jn = atoll(j);
	if (less(cn, jn)) {
		minabs = llabs(cn - jn);
		mincn = cn;
		minjn = jn;
		strcpy(minc, c);
		strcpy(minj, j);
	}
}

void solve(const char *c, const char *j, int i) {
	int k;
	char cc[19], jj[19];

	strcpy(cc, c);
	strcpy(jj, j);

	if (cc[i] == '?' && jj[i] == '?') {
		cc[i] = jj[i] = '0';
		solve(cc, jj, i + 1);

		cc[i] = '1';
		jj[i] = '0';
		for (k = i + 1; cc[k]; k++) {
			cc[k] = cc[k] == '?' ? '0' : cc[k];
			jj[k] = jj[k] == '?' ? '9' : jj[k];
		}
		check_and_set(cc, jj);
		strcpy(cc, c);
		strcpy(jj, j);

		cc[i] = '0';
		jj[i] = '1';
		for (k = i + 1; cc[k]; k++) {
			cc[k] = cc[k] == '?' ? '9' : cc[k];
			jj[k] = jj[k] == '?' ? '0' : jj[k];
		}
		check_and_set(cc, jj);
	} else {
		if (cc[i] == '?' && jj[i] != '?') {
			if (jj[i] != '0') {
				cc[i] = jj[i] - 1;
				for (k = i + 1; cc[k]; k++) {
					cc[k] = cc[k] == '?' ? '9' : cc[k];
					jj[k] = jj[k] == '?' ? '0' : jj[k];
				}
				check_and_set(cc, jj);
				strcpy(cc, c);
				strcpy(jj, j);
			}
			if (jj[i] != '9') {
				cc[i] = jj[i] + 1;
				for (k = i + 1; cc[k]; k++) {
					cc[k] = cc[k] == '?' ? '0' : cc[k];
					jj[k] = jj[k] == '?' ? '9' : jj[k];
				}
				check_and_set(cc, jj);
				strcpy(cc, c);
				strcpy(jj, j);
			}
			cc[i] = jj[i];
			solve(cc, jj, i + 1);
		} else if (cc[i] != '?' && jj[i] == '?') {
			if (cc[i] != '0') {
				jj[i] = cc[i] - 1;
				for (k = i + 1; jj[k]; k++) {
					jj[k] = jj[k] == '?' ? '9' : jj[k];
					cc[k] = cc[k] == '?' ? '0' : cc[k];
				}
				check_and_set(cc, jj);
				strcpy(cc, c);
				strcpy(jj, j);
			}
			if (cc[i] != '9') {
				jj[i] = cc[i] + 1;
				for (k = i + 1; jj[k]; k++) {
					jj[k] = jj[k] == '?' ? '0' : jj[k];
					cc[k] = cc[k] == '?' ? '9' : cc[k];
				}
				check_and_set(cc, jj);
				strcpy(cc, c);
				strcpy(jj, j);
			}
			jj[i] = cc[i];
			solve(cc, jj, i + 1);
		} else {
			if (cc[i] < jj[i]) {
				for (k = i + 1; cc[k]; k++) {
					cc[k] = cc[k] == '?' ? '9' : cc[k];
					jj[k] = jj[k] == '?' ? '0' : jj[k];
				}
				check_and_set(cc, jj);
			} else if (cc[i] > jj[i]) {
				for (k = i + 1; cc[k]; k++) {
					cc[k] = cc[k] == '?' ? '0' : cc[k];
					jj[k] = jj[k] == '?' ? '9' : jj[k];
				}
				check_and_set(cc, jj);
			} else {
				solve(cc, jj, i + 1);
			}
		}
	}
}

int main(void) {
	int cs;
	int t;

	scanf("%d", &t);
	for (cs = 1; cs <= t; cs++) {
		char c[19], j[19];

		scanf("%s %s", c, j);

		minabs = mincn = minjn = INF;
		solve(c, j, 0);

		printf("Case #%d: %s %s\n", cs, minc, minj);
	}

	return 0;
}
