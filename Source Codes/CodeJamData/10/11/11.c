#include <stdio.h>
#include <stdbool.h>

#define NMAX 50
static char A[NMAX][NMAX+1], B[NMAX][NMAX];

static bool has(int n, int k, char ch) {
	int i, j, c;

	for (i = 0; i != n; ++i) {
		c = 0;
		for (j = 0; j != n; ++j) {
			if (B[i][j] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	for (j = 0; j != n; ++j) {
		c = 0;
		for (i = 0; i != n; ++i) {
			if (B[i][j] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	for (i = 0; i <= n-k; ++i) {
		c = 0;
		for (j = 0; i+j != n; ++j) {
			if (B[i+j][j] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	for (j = 1; j <= n-k; ++j) {
		c = 0;
		for (i = 0; i+j != n; ++i) {
			if (B[i][i+j] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	for (i = k-1; i != n; ++i) {
		c = 0;
		for (j = 0; j <= i; ++j) {
			if (B[i-j][j] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	for (j = 1; j <= n-k; ++j) {
		c = 0;
		for (i = 0; i+j != n; ++i) {
			if (B[n-i-1][j+i] != ch)
				c = 0;
			else
				++c;
			if (c == k)
				return true;
		}
	}

	return false;
}

int main() {
	int tc, cs, n, k, i, j, c;
	bool red, blue;
	const char* ans;
	
	scanf("%d", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%d%d", &n, &k);
		for (i = 0; i != n; ++i)
			scanf("%s", A[i]);

		for (i = 0; i != n; ++i)
			for (j = 0; j != n; ++j)
				B[j][n-i-1] = A[i][j];

		for (j = 0; j != n; ++j) {
			c = 0;
			for (i = n-1; i >= 0; --i) {
				if (B[i][j] == '.')
					++c;
				else if (c != 0) {
					B[i+c][j] = B[i][j];
					B[i][j] = '.';
				}
			}
		}

		red = has(n, k, 'R');
		blue = has(n, k, 'B');

		if (red && blue)
			ans = "Both";
		else if (red && !blue)
			ans = "Red";
		else if (!red && blue)
			ans = "Blue";
		else
			ans = "Neither";
		printf("Case #%d: %s\n", cs+1, ans);
	}

	return 0;
}


