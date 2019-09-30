#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#define MINUS_ONE       (0 << 7)
#define PLUS_ONE        (1 << 7)
#define PLUS_I          (2 << 7)
#define MINUS_I         (3 << 7)
#define PLUS_J          (4 << 7)
#define MINUS_J         (5 << 7)
#define PLUS_K          (6 << 7)
#define MINUS_K         (7 << 7)

int solve_test_case(short *lut, short *rlut) {
	int64_t l, x, i;
	int c;
	short overall_val = PLUS_ONE; // value of the entire string
	short starting_val = PLUS_ONE; // value of the beginning (expected: i)
	short ending_val = PLUS_ONE; // value of the beginning (expected: i)
	int val_at_fronteers_from_start = 0;
	int val_at_fronteers_from_end = 0;
	int i_found_at = -1;
	int k_found_at = -1;
	char buf[10002];

	scanf("%" SCNd64 "%" SCNd64, &l, &x);
	while (fgetc(stdin) != '\n');
	for (i = 0; i < l; ++i) {
		int c = fgetc(stdin);
		assert((c == 'i') || (c == 'j') || (c == 'k'));
		buf[i] = c;
	}

	for (i = 0; i < l; ++i) {
		int c = buf[i];
		overall_val = lut[overall_val | c];
	}

	for (i = 0; starting_val != PLUS_I; ++i) {
		if ((i % l) == 0) {
			if (val_at_fronteers_from_start &(1<<(starting_val>>7)))
				break;
			val_at_fronteers_from_start |= 1 << (starting_val>>7);
		}
		int c = buf[i % l];
		starting_val = lut[starting_val | c];
	}
	if (starting_val == PLUS_I)
		i_found_at = i;
	else
		return 0;

	for (i = 0; ending_val != PLUS_K; ++i) {
		if ((i % l) == 0) {
			if (val_at_fronteers_from_end & (1<<(ending_val>>7)))
				break;
			val_at_fronteers_from_end |= 1 << (ending_val>>7);
		}
		int c = buf[l - 1 - (i % l)];
		ending_val = rlut[ending_val | c];
	}
	if (ending_val == PLUS_K)
		k_found_at = i;
	else
		return 0;

	if ((i_found_at + k_found_at) > (l*x))
		return 0;

	if (overall_val == PLUS_ONE) {
		// overall_val is correct
	} else if (overall_val == MINUS_ONE) {
		overall_val ^= ((x-1) % 2) << 7;
	} else {
		if (x % 2) {
			overall_val ^= ((x/2) % 2) << 7;
		} else {
			overall_val = MINUS_ONE;
			overall_val ^= ((x/2-1) % 2) << 7;
		}
	}

	return (overall_val == MINUS_ONE);
}

int main(void) {
	short lut[8 << 7];
	short rlut[8 << 7];

	lut[MINUS_ONE | 'i'] = MINUS_I;
	lut[MINUS_ONE | 'j'] = MINUS_J;
	lut[MINUS_ONE | 'k'] = MINUS_K;

	lut[PLUS_ONE | 'i'] = PLUS_I;
	lut[PLUS_ONE | 'j'] = PLUS_J;
	lut[PLUS_ONE | 'k'] = PLUS_K;

	lut[MINUS_I | 'i'] = PLUS_ONE;
	lut[MINUS_I | 'j'] = MINUS_K;
	lut[MINUS_I | 'k'] = PLUS_J;

	lut[PLUS_I | 'i'] = MINUS_ONE;
	lut[PLUS_I | 'j'] = PLUS_K;
	lut[PLUS_I | 'k'] = MINUS_J;

	lut[MINUS_J | 'i'] = PLUS_K;
	lut[MINUS_J | 'j'] = PLUS_ONE;
	lut[MINUS_J | 'k'] = MINUS_I;

	lut[PLUS_J | 'i'] = MINUS_K;
	lut[PLUS_J | 'j'] = MINUS_ONE;
	lut[PLUS_J | 'k'] = PLUS_I;

	lut[MINUS_K | 'i'] = MINUS_J;
	lut[MINUS_K | 'j'] = PLUS_I;
	lut[MINUS_K | 'k'] = PLUS_ONE;

	lut[PLUS_K | 'i'] = PLUS_J;
	lut[PLUS_K | 'j'] = MINUS_I;
	lut[PLUS_K | 'k'] = MINUS_ONE;

	for (int i = 0; i < 8; ++i) {
		rlut[(i<<7) | 'i'] = lut[(i<<7) | 'i'] ^ ((i < 2)? 0 : 128);
		rlut[(i<<7) | 'j'] = lut[(i<<7) | 'j'] ^ ((i < 2)? 0 : 128);
		rlut[(i<<7) | 'k'] = lut[(i<<7) | 'k'] ^ ((i < 2)? 0 : 128);
	}

	rlut[MINUS_I | 'i'] = PLUS_ONE;
	rlut[MINUS_J | 'j'] = PLUS_ONE;
	rlut[MINUS_K | 'k'] = PLUS_ONE;

	rlut[PLUS_I | 'i'] = MINUS_ONE;
	rlut[PLUS_J | 'j'] = MINUS_ONE;
	rlut[PLUS_K | 'k'] = MINUS_ONE;

	int n_test_cases;
	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int answer = solve_test_case(lut, rlut);
		printf("Case #%d: %s\n", i + 1, answer? "YES":"NO");
	}
	return 0;
}

