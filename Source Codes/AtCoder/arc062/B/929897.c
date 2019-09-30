#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int gp, i, len, score;
	char s[100010];
	scanf("%s", &s);
	len = strlen(s);

	gp = 1;
	score = 0;
	for (i=1;i<len;i++) {
		if (s[i] == 'g') {
			if (gp>0) { score++; gp--; }
			else { gp++; }
		} else {
			if (gp>0) { gp--; }
			else { score--; gp++; }
		}
	}

	printf("%d\n", score);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100010]’ [-Wformat=]
  scanf("%s", &s);
        ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &s);
  ^