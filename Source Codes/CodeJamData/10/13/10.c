#include <stdio.h>
#include <stdbool.h>

static bool win(int a, int b) {
	if (a > b)
		return win(b, a);

	if (b >= 2*a)
		return true;

	return !win(a, b-a);
}

int main() {
	int tc, cs, a, b, a0, a1, b0, b1, c;

	scanf("%d", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%d%d%d%d", &a0, &a1, &b0, &b1);

		c = 0;
		for (a = a0; a <= a1; ++a)
			for (b = b0; b <= b1; ++b)
				if (win(a, b))
					++c;

		printf("Case #%d: %d\n", cs+1, c);
	}

	return 0;
}


