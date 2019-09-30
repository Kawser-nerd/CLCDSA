#include <stdio.h>
#include <err.h>

#define read1(fmt, p)						\
	do {							\
		if (scanf(fmt, p) != 1)				\
			err(1, "%s:%d", __FILE__, __LINE__);	\
	} while (0)

static int T, m, r, s;
static char S[1002];

int main(void) {
	read1("%d", &T);
	for (int t = 1; t <= T; t++) {
		read1("%d", &m);
		read1("%s", S);
		r = 0;
		s = 0;
		for (int i = 0; i <= m; i++) {
			if (s < i) {
				r += i - s;
				s = i;
			}
			s += S[i] - '0';
		}
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}
