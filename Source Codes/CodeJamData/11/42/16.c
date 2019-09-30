#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long mass[500][500];

int main() {
	int T, caseNum, R, C, D, r, c, K, r1, c1, r0, c0, rM, cM, found;
	long long rTot, cTot;
	rM = r0+r1;
	cM = c0+c1;
	char ch;

	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {
		scanf(" %d %d %d ", &R, &C, &D);
		for (r = 0; r < R; r++) {
			for (c = 0; c < C; c++) {
				scanf("%c", &ch);
				mass[r][c] = D+(int)(ch-'0');
			}
			scanf(" ");
		}

		K = (R < C ? R : C) + 1;
		found = 0;
		while (--K >= 3) {
			for (r1 = K-1; r1 < R; r1++)
				for (c1 = K-1; c1 < C; c1++) {
					r0 = r1-K+1;
					c0 = c1-K+1;
					rM = r0+r1;
					cM = c0+c1;
					rTot = cTot = 0;
					for (r = r0; r <= r1; r++)
						for (c = c0; c <= c1; c++) {
							if ((r == r0 || r == r1) && (c == c0 || c == c1))
								continue;
							rTot += (long)(2*r-rM)*mass[r][c];
							cTot += (long)(2*c-cM)*mass[r][c];
						}
					if (rTot == 0 && cTot == 0) {
						found = 1;
						r1 = R;
						c1 = C;
					}
				}
			if (found)
				break;
		}

		printf("Case #%d: ", caseNum);
		if (K >= 3)
			printf("%d", K);
		else
			printf("IMPOSSIBLE");
		printf("\n");
	}
	return 0;
}

