#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef char* string;

// Represntation:
// Lower 4 bits are either 1/i/j/k,
// Upper 4 bits are either 0 for + and 1 for -.

typedef uint8_t quat;

typedef enum QUAT_BASE {
	q1, qi, qj, qk
} quat_base;

#define	QUAT_PLUS		0
#define	QUAT_MINUS		1 << 4
#define QUAT_SIGN(q)	((q) & QUAT_MINUS)
#define QUAT_POS(q)		(QUAT_SIGN(q) == QUAT_PLUS)
#define QUAT_NEG(q)		(QUAT_SIGN(q) == QUAT_MINUS)
#define QUAT_TO_POS(q)	((q) & 0xF)

quat to_quat(char c) {
	switch (c) {
	case 'i':
		return qi;
	case 'j':
		return qj;
	case 'k':
		return qk;
	}
	return 0;
}

quat inv(quat a) {
	if (QUAT_TO_POS(a) == q1) {
		return q1;
	}
	return a ^ QUAT_MINUS;
}

quat mul(quat a, quat b) {
	bool neg = QUAT_NEG(a) ^ QUAT_NEG(b);
	quat res = q1;

	a = QUAT_TO_POS(a);
	b = QUAT_TO_POS(b);

	if (a == q1) {
		res = b;
	}
	else if (b == q1) {
		res = a;
	}
	else {
		switch (a) {
		case qi:
			switch (b) {
			case qi:
				neg = !neg;
				res = q1;
				break;
			case qj:
				res = qk;
				break;
			case qk:
				neg = !neg;
				res = qj;
				break;
			}
			break;
		case qj:
			switch (b) {
			case qi:
				neg = !neg;
				res = qk;
				break;
			case qj:
				neg = !neg;
				res = q1;
				break;
			case qk:
				res = qi;
				break;
			}
			break;
		case qk:
			switch (b) {
			case qi:
				res = qj;
				break;
			case qj:
				neg = !neg;
				res = qi;
				break;
			case qk:
				neg = !neg;
				res = q1;
				break;
			}
			break;
		}
	}

	if (neg) {
		res |= QUAT_MINUS;
	}

	return res;
}

bool solve(uint32_t L, uint64_t X, char *S) {
	uint32_t i, j;

	bool result = false;

	// X reduction.
	if (X > 12) {
		X = 12 + X % 4;
	}

	// Create full string.
	uint32_t fL = L * X;
	quat *fQ = malloc(fL);
	for (i = 0; i < fL; i++) {
		fQ[i] = to_quat(S[i % L]);
	}

	// Initialize stuff.
	quat left, middle, right, left_rest;

	left = q1;
	left_rest = q1;
	for (i = 0; i < fL; i++) {
		left_rest = mul(left_rest, fQ[i]);
	}

	// Start solving.
	// i is where middle starts.
	for (i = 1; i < fL && !result; i++) {
		left = mul(left, fQ[i - 1]);
		left_rest = mul(inv(fQ[i - 1]), left_rest);

		if (left != qi) {
			continue;
		}

		// Initialize stuff.
		middle = q1;
		right = left_rest;

		// j is where right starts.
		for (j = i + 1; j < fL; j++) {
			middle = mul(middle, fQ[j - 1]);
			right = mul(inv(fQ[j - 1]), right);

			if (middle == qj && right == qk) {
				result = true;
				break;
			}
		}
	}

	free(fQ);
	return result;
}

int main() {
	freopen("D:\\projects\\c\\codejam\\2015qualC\\Release\\input.txt", "r", stdin);
	freopen("D:\\projects\\c\\codejam\\2015qualC\\Release\\output.txt", "w", stdout);

	uint32_t T, U;
	scanf("%d", &T);

	for (uint32_t i = 1; i <= T; i++) {
		uint32_t L;
		uint64_t X;
		scanf("%d %lld", &L, &X);

		string S = malloc(L + 1);
		scanf("%s", S);

		bool res = solve(L, X, S);
		printf("Case #%d: %s\n", i, res ? "YES" : "NO");

		free(S);
	}

	return 0;
}