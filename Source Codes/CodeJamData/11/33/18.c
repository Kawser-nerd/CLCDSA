#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFLEN 8192

char buf[BUFLEN];
int notes[10000];

int main() {
	int T, caseNum, N, L, H, i, x, note, okay;

	scanf(" %d", &T);
	for (caseNum = 1; caseNum <= T; caseNum++) {
		scanf(" %d %d %d", &N, &L, &H);
		for (i = 0; i < N; i++)
			scanf(" %d", &notes[i]);

		for (x = L; x <= H; x++) {
			okay = 1;
			for (i = 0; i < N; i++) {
				note = notes[i];
				if (x%note == 0 || note%x == 0)
					continue;
				okay = 0;
				break;
			}
			if (okay)
				break;
		}

		printf("Case #%d: ", caseNum);
		if (x <= H)
			printf("%d", x);
		else
			printf("NO");
		printf("\n");
	}
}
