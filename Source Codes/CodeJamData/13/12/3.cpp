#include <cstdio>
#include <algorithm>
#include <assert.h>
using namespace std;

#define NMAX 10005
int values[NMAX];

int nextLarger[NMAX];
int s[NMAX];
int slen;

int main() {
	int ncases;
	scanf("%d", &ncases);
	for (int casen = 1; casen <= ncases; casen++) {
		int e, r, n;
		scanf("%d", &e);
		scanf("%d", &r);
		scanf("%d", &n);
		if (r > e) {
			r = e;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &values[i]);
		}
		
		slen = 0;
		for (int i = n-1; i >= 0; i--) {
			while (slen > 0 && values[s[slen-1]] < values[i]) {
				slen--;
			}
			nextLarger[i] = slen > 0 ? s[slen-1] : -1;
			s[slen++] = i;
		}

		long long total = 0;
		long long currentE = (long long) e;
		for (int i = 0; i < n; i++) {
			int j = nextLarger[i];
			long long amt;
			if (j == -1) {
				amt = currentE;
			} else {
				amt = currentE - max(0LL, (long long)e - (long long)r*(long long)(j-i));
				if (amt < 0) {
					amt = 0;
				}
			}
			assert (amt >= 0);
			assert (amt <= currentE);
			total += amt * (long long)values[i];
			currentE -= amt;
			currentE += (long long)r;
		}
		printf("Case #%d: %lld\n", casen, total);
	}
}
