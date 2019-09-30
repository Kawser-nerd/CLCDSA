#include <stdio.h>

int main(void) {
	int T, caseCount;
	if (scanf("%d", &T) != 1) return 1;
	for (caseCount = 1; caseCount <= T; caseCount++) {
		char S[128];
		int count = 1, i;
		if (scanf("%127s", S) != 1) return 1;
		printf("Case #%d: ", caseCount);
		for (i = 0; S[i + 1] != '\0'; i++) {
			if (S[i] != S[i + 1]) count++;
		}
		printf("%d\n", count - (S[i] == '+'));
	}
	return 0;
}

/*
Consecutive pancakes with same sides up should be able to be considered as one pancake. (not proved)

+ -> 0
- -> 1
-+ -> 1
+- -> 2
+-+ -> 2
-+- -> 3

answer should be
  N   if the last character is -
  N-1 if the last character is +
where N is # of sections of consecutive same characters.
(not proved)

*/
