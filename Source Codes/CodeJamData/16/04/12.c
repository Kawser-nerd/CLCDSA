#include <stdio.h>

void printll(long long x) {
	if (x >= 10) printll(x / 10);
	putchar('0' + (int)(x % 10));
}

int main(void) {
	int T, caseCount;
	if (scanf("%d", &T) != 1) return 1;
	for (caseCount = 1; caseCount <= T; caseCount++) {
		int K, C, S;
		int requiredNum;
		if (scanf("%d%d%d", &K, &C, &S) != 3) return 1;
		printf("Case #%d:", caseCount);
#if 0
		if (K == S) {
			/* examine tiles which represent the original sequence (simple solution for small case) */
			long long position[128];
			long long len = 1;
			int i, j;
			for (i = 0; i < K; i++) position[i] = i;
			for (i = 1; i < C; i++) {
				len *= K;
				for (j = 0; j < K; j++) {
					position[j] = j * len + position[j];
				}
			}
			for (i = 0; i < K; i++) {
				putchar(' ');
				printll(position[i] + 1);
			}
			putchar('\n');
		} else
#endif
		if (S >= (requiredNum = (K + C - 1) / C)) {
			int i, j;
			int wantPos = 0;
			for (i = 0; i < requiredNum; i++) {
				long long len = 1;
				long long currentPos = 0;
				for (j = 0; j < C; j++) {
					currentPos = wantPos * len + currentPos;
					if (wantPos + 1 < K) wantPos++;
					if (j + 1 < C) len *= K;
				}
				putchar(' ');
				printll(currentPos + 1);
			}
			putchar('\n');
		} else {
			puts(" IMPOSSIBLE");
		}
	}
	return 0;
}

/*

complexity 1
[orig]
complexity 2
[orig][gold][orig]
complexity 3
Each L in complexity 2 will be [orig], and each G in complexity 2 will be [gold]
so, regions of complexity 2 made from L in complexity 1 will be [orig][gold][orig]
and regions of complexity 2 made from G in complexity 1 will be [gold][gold][gold]
therefore, this can be represented as [complexity 2][big gold][complexity 2]
complexity 4
the sequence which is same as complexity 2 will be complexity 3
the sequence which is all gold will be all gold
therefore, this can be represented as [complexity 3][all gold][complexity 3]

repeating this, making complexity X+1 from cpmplexity X will be:
* The part came from L in original will be complexity X
* The part came from G in original will be all G

-----

[0][1]
[0][01] [01][1]
[0][01][01][01] [01][01][01][1]

[0][1][2]
[0][01][02] [01][1][12] [02][12][2]
[0][01][02][01][01][012][02][012][02] [01][01][012][01][1][12][012][12][12] [02][012][02][012][12][12][02][12][2]

[0][1][2][3]
[0][01][02][03] [01][1][12][13] [02][12][2][23] [03][13][23][3]
[0][01][02][03][01][01][012][013][02][012][02][023][03][013][023][03]
  [01][01][012][013][01][1][12][13][012][12][12][123][013][13][123][13]
  [02][012][02][023][012][12][12][123][02][12][2][23][023][123][23][23]
  [03][013][023][03][013][13][123][13][023][123][23][23][03][13][23][3]

n-th region is ORed with n

-----

(not proved)
it is possible if you can examine ceil(K/C) tiles or more
it is not possible otherwise

Then, how to determine where to examine?
In the section -> get OR
explore the sections!

*/
