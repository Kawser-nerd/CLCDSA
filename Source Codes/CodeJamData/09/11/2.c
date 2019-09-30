#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static int f(int n, int b) {
	int s = 0, x;
	while (n != 0) {
		x = n%b;
		s+= x*x;
		n/= b;
	}
	return s;
}

static bool is_happy(int x0, int b) {
	int p, l, t, h, u, i;

	p = l = 1;
	t = x0;
	h = f(x0, b);
	if (t == 1 || h == 1)
		return true;
	while (t != h) {
		if (p == l) {
			t = h;
			p*= 2;
			l = 0;
		}
		h = f(h, b);
		if (h == 1)
			return true;
		++l;
	}

	u = 0;
	t = h = x0;
	for (i = l; i != 0; --i) {
		h = f(h, b);
		if (h == 1)
			return true;
	}
	while (t != h) {
		t = f(t, b);
		h = f(h, b);
		if (t == 1 || h == 1)
			return true;
		++u;
	}

	return false;
}

int main(void) {
	char line[1024];
	int tc, cs;
	int n, i, x;
	int A[100];
	char* p;

	scanf(" %[^\n]", line);
	sscanf(line, "%d", &tc);
	for (cs = 1; cs <= tc; ++cs) {
		scanf(" %[^\n]", line);
		n = 0;
		for (p = strtok(line, " "); p; p = strtok(0, " "))
			sscanf(p, "%d", &A[n++]);

		for (x = 2;; ++x) {
			for (i = 0; i != n; ++i)
				if (!is_happy(x, A[i]))
					break;
			if (i == n)
				break;
		}

		printf("Case #%d: %d\n", cs, x);
		fflush(stdout);
	}

	return 0;
}


