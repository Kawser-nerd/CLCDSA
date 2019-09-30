#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <assert.h>

// --------------- //
// Data structures //
// --------------- //

typedef struct {
	int index;
	int x;
	int r;
	int c;
	char *outcome;
} test_case_t;

typedef struct {
	int width;
	int height;
	unsigned char shape[8];
} omino_t;

typedef struct {
	int n_free;
	int n_fixed;
	omino_t *free;
	omino_t *fixed;
} omino_set_t;

typedef struct {
	int first_free_idx;
	int width;
	int height;
	int rows[20];
} grid_t;

test_case_t test_cases[100];
omino_set_t ominoes[8];

// ------------- //
// Grid handling //
// ------------- //

void grid_reset(grid_t *grid, int w, int h) {
	grid->first_free_idx = 0;
	grid->width = w;
	grid->height = h;
	for (int i = 0; i < 20; ++i) {
		grid->rows[i] = (~0) << w;
	}
}

void grid_xor_omino(grid_t *grid, omino_t *omino, int r, int c) {
	for (int i = 0; i < omino->height; ++i) {
		if (r+i > grid->height)
			return;
		grid->rows[r+i] ^= omino->shape[i] << c;
	}
}

int grid_can_place_omino(grid_t *grid, omino_t *omino, int r, int c) {
	if ((r + omino->height) > grid->height)
		return 0;
	if ((c + omino->width) > grid->width)
		return 0;
	for (int i = 0; i < omino->height; ++i) {
		if ((omino->shape[i] << c) & (grid->rows[r+i]))
			return 0;
	}
	return 1;
}

void grid_print(grid_t *grid, FILE *fp) {
	fprintf(fp, " ");
	for (int c = 0; c < grid->width; ++c) {
		fprintf(fp, "--");
	}
	fprintf(fp, "\n");
	for (int r = 0; r < grid->height; ++r) {
		fprintf(fp, "|");
		for (int c = 0; c < grid->width; ++c) {
			fprintf(fp, "%s", (grid->rows[r] & (1<<c))? "[]":"  ");
		}
		fprintf(fp, "|\n");
	}
}


int paint_free_region(grid_t *grid, int r, int c) {
	int rv;
	if ((r < 0) || (c < 0) || (r >= grid->height) || (c >= grid->width))
		return 0;
	if (grid->rows[r] & (1 << c))
		return 0;
	grid->rows[r] |= 1 << c;

	rv = 1;
	rv += paint_free_region(grid, r+1, c);
	rv += paint_free_region(grid, r-1, c);
	rv += paint_free_region(grid, r, c+1);
	rv += paint_free_region(grid, r, c-1);

	return rv;
}

int grid_is_solvable(grid_t *grid, int x) {
	int ffi;
	int ffi_bak = grid->first_free_idx;

	omino_set_t *os = &(ominoes[x]);
	//grid_print(grid, stderr);
	
	int rows_bak[20];
	memcpy(rows_bak, grid->rows, 20*sizeof(int));
	for (int i = 0; i < grid->width*grid->height; ++i) {
		int r = i / grid->width;
		int c = i % grid->width;
		if (!(grid->rows[r] & (1 << c))) {
			int n = paint_free_region(grid, r, c);
			//fprintf(stderr, "Free region size: %d\n", n);
			if (n % x) {
				memcpy(grid->rows, rows_bak, 20*sizeof(int));
				return 0;
			}
		}
	}
	memcpy(grid->rows, rows_bak, 20*sizeof(int));

	// At that point, if all x-sized ominoes are indeed in the ominoes[x]
	// set, it is possible to return 1 and call it a day. The following is 
	// a bit over engeenered, but allows the function to continue working
	// when only a subset of x-sized ominoes is in ominoes[x].
	
	for (ffi = ffi_bak; grid->rows[ffi/30] & (1<<(ffi%30)); ffi++) {
		if ((ffi / 30) < (grid->height-1))
			continue;
		if ((ffi % 30) < (grid->width-1))
			continue;
		grid->first_free_idx = ffi_bak;
		return 1;
	}
	grid->first_free_idx = ffi;
	for (int i = 0; i < os->n_fixed; ++i) {
		omino_t *o = &(os->fixed[i]);
		for (int c = 0; c < (grid->width - o->width + 1); ++c) {
			if (grid_can_place_omino(grid, o, ffi/30, c)) {
				grid_xor_omino(grid, o, ffi/30, c);
				if (grid->rows[ffi/30] & (1 << (ffi%30))) {
					if (grid_is_solvable(grid, x)) {
						grid->first_free_idx = ffi_bak;
						grid_xor_omino(grid, o, 
								ffi/30, c);
						return 1;
					}
				}
				grid_xor_omino(grid, o, ffi/30, c);
			}
		}
	}
	grid->first_free_idx = ffi_bak;
	return 0;
}

int grid_is_solvable_using_omino(grid_t *grid, int x, omino_t *o) {
	int r_max = grid->height - o->height + 1;
	int c_max = grid->width - o->width + 1;
	for (int r = 0; r < r_max; ++r) {
		for (int c = 0; c < c_max; ++c) {
			if (!grid_can_place_omino(grid, o, r, c))
				continue;
			grid_xor_omino(grid, o, r, c);
			int ok = grid_is_solvable(grid, x);
			grid_xor_omino(grid, o, r, c);
			if (ok) {
				return 1;
			}
		}
	}
	return 0;
}

// -------------- //
// Omino handling //
// -------------- //

void omino_copy(omino_t *dst, omino_t *src) {
	if (dst == src)
		return;
	memcpy(dst, src, sizeof(omino_t));
}

void omino_shape(omino_t *dst, uint64_t shape) {
	dst->width = 0;
	dst->height = 0;
	for (int i = 0; i < 8; ++i) {
		dst->shape[i] = (shape >> (8*i)) & 0xff;
		if (dst->shape[i] > 0)
			dst->height = i + 1;
		for (int j = dst->width; j < 7; ++j) {
			if (dst->shape[i] & (1 << j))
				dst->width = j + 1;
		}
	}
}

int omino_cmp(omino_t *a, omino_t*b) {
	int64_t shape_a, shape_b;
	int64_t diff;
	shape_a = shape_b = 0;
	for (int i = 0; i < 7; ++i) {
		shape_a += ((int64_t) a->shape[i]) << (8*i);
		shape_b += ((int64_t) b->shape[i]) << (8*i);
	}
	diff = shape_a - shape_b;
	return (diff < 0)? -1 : ((diff > 0)? 1 : 0);
}

int omino_extend(omino_t *dst_ominoes, omino_t *omino) {
	int rv = 0;
	uint64_t o, d, l, adjascent;
	uint64_t mask;
	adjascent  = (1ULL << (32+8)) | (1ULL << (32+1));
	adjascent |= (1ULL << (32-1)) | (1ULL << (32-8));
	o = d = l = 0;
	for (int i = 0; i < 8; ++i) {
		o |= ((uint64_t) omino->shape[i]) << (8*i);
		l |= ((uint64_t) omino->shape[i]) << (8*i + 1);
		d |= ((uint64_t) omino->shape[i]) << (8*i + 8);
	}
	for (int i = 0; i < 56; ++i) {
		if ((i % 8) == 7)
			continue;
		mask = (i < 32)? (adjascent >> (-i+32)) : (adjascent << (i-32));
		if ((o & mask) && !(o & (1 << i))) {
			omino_shape(&(dst_ominoes[rv++]), o | (1 << i));
		}
	}
	for (int i = 0; i < 7; ++i) {
		if (d & (1 << (i+8))) {
			omino_shape(&(dst_ominoes[rv++]), d | (1 << i));
		}
	}
	for (int i = 0; i < 56; i += 8) {
		if (l & (1 << (i+1))) {
			omino_shape(&(dst_ominoes[rv++]), l | (1 << i));
		}
	}
	return rv;
}

void omino_transform(omino_t *omino, int mode) {
	if (mode == 0)
		return;
	if (mode & 1) {
		// Diagonal symmetry
		uint64_t shape = 0;
		for (int i = 0; i < 64; ++i) {
			if (omino->shape[i % 8] & (1 << (i/8)))
				shape |= 1ULL << i;
		}
		omino_shape(omino, shape);
	}
	if (mode & 2) {
		// Horizontal symmetry
		uint64_t shape = 0;
		int w = omino->width;
		for (int i = 0; i < 64; ++i) {
			if (((i%8) < w) && (omino->shape[i/8] & (1<<(w-i%8-1))))
				shape |= 1ULL << i;
		}
		omino_shape(omino, shape);
	}
	if (mode & 4) {
		// Vertical symmetry
		uint64_t shape = 0;
		int h = omino->height;
		for (int i = 0; i < h; ++i) {
			shape |= ((uint64_t) omino->shape[h - i - 1]) << (8*i);
		}
		omino_shape(omino, shape);
	}
}

int omino_is_canonical(omino_t *omino) {
	omino_t tmp;
	for (int i = 1; i < 8; ++i) {
		omino_copy(&tmp, omino);
		omino_transform(&tmp, i);
		if (omino_cmp(&tmp, omino) > 0)
			return 0;
	}
	return 1;
}

void generate_ominoes(int size) {
	if (size > 1)
		generate_ominoes(size - 1);

	omino_set_t *sm1 = &(ominoes[size - 1]);
	omino_set_t *s = &(ominoes[size]);

	if (size == 1) {
		s->n_free = 1;
		s->n_fixed = size;
		s->free = calloc(1, sizeof(omino_t));
		s->fixed = calloc(1, sizeof(omino_t));
		s->free[0].width = size;
		s->free[0].height = 1;
		s->free[0].shape[0] = (1 << size) - 1;
		omino_copy(&(s->fixed[0]), &(s->free[0]));
		return;
	} else {
		s->fixed = calloc(17*sm1->n_fixed, sizeof(omino_t));
		s->n_fixed = 0;

		// Extending (X-1)-ominoes by one block
		for (int i = 0; i < sm1->n_fixed; ++i) {
			s->n_fixed += omino_extend(
					&(s->fixed[s->n_fixed]),
					&(sm1->fixed[i])
			);
		}

		// Removing doubles
		qsort(
				s->fixed,
				s->n_fixed,
				sizeof(omino_t),
				(int (*)(const void *, const void *)) omino_cmp
		);
		int j = 0;
		for (int i = 1; i < s->n_fixed; ++i) {
			omino_t *o = &(s->fixed[i]);
			if (omino_cmp(&(s->fixed[j]), o) != 0) {
				omino_copy(&(s->fixed[++j]), o);
			}
		}
		s->n_fixed = j + 1;

		// Generating free X-ominoes (from fixed versions)
		s->free = calloc(s->n_fixed, sizeof(omino_t));
		j = 0;
		for (int i = 0; i < s->n_fixed; ++i) {
			omino_t *o = &(s->fixed[i]);
			if (omino_is_canonical(o)) {
				omino_copy(&(s->free[j++]), o);
			}
		}
		s->n_free = j;
	}
}

void omino_array_print(omino_t *ominoes, int n, FILE *fp) {
	for (int i = 0; i < n; i += 5) {
		for (int y = 0; y < 7; ++y) {
			for (int j = 0; j < 5; ++j) {
				if ((i+j) >= n)
					continue;
				for (int x = 0; x < 8; ++x) {
					int b = ominoes[i+j].shape[y] & (1<<x);
					fprintf(fp, "%s", b? "[]":"  ");
				}
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");
	}
}

void omino_set_print(omino_set_t *set, FILE *fp) {
	fprintf(fp, "Free ominoes (%d):\n", set->n_free);
	omino_array_print(set->free, set->n_free, fp);
	fprintf(fp, "Fixed ominoes (%d):\n", set->n_fixed);
	omino_array_print(set->fixed, set->n_fixed, fp);
}

void *solve_test_case(void *test_case) {
	test_case_t *tc = test_case;
	grid_t grid;
	omino_set_t *os = &(ominoes[tc->x]);

	for (int i = 0; i < os->n_free; ++i) {
		omino_t *o = &(os->free[i]);
		int x = tc->x;

		grid_reset(&grid, tc->r, tc->c);
		int ok = grid_is_solvable_using_omino(&grid, x, o);

		if (!ok) {
			grid_reset(&grid, tc->c, tc->r);
			ok = grid_is_solvable_using_omino(&grid, x, o);

			if (!ok) {
				tc->outcome = "RICHARD";
				return NULL;
			}
		}
	}
	
	tc->outcome = "GABRIEL";
	return NULL;
}

int main(void) {
	int n_test_cases;
	int n_non_trivial_test_cases = 0;
	test_case_t test_cases[100];

	generate_ominoes(6);

	//omino_set_print(&(ominoes[4]), stdout);
	//return 0;

	scanf("%d", &n_test_cases);
	for (int i = 0; i < n_test_cases; ++i) {
		int e;
		test_case_t *tc = &(test_cases[i]);
		scanf("%d %d %d", &(tc->x), &(tc->r), &(tc->c));
		tc->outcome = "RICHARD";
		if (tc->x >= 7)
			continue; // There are X-ominos with holes, Richard wins
		if ((tc->x > tc->r) && (tc->x > tc->c))
			continue; // 'I' X-ominos do not fit, Richard wins
		if (((tc->r * tc->c) % tc->x) != 0)
			continue; // Grid size not multiple of X, Richard wins
		tc->index = i;
		tc->outcome = "???";
		solve_test_case(tc);
		assert(e == 0);
		n_non_trivial_test_cases++;
	}

	for (int i = 0; i < n_test_cases; ++i) {
		test_case_t *tc = &(test_cases[i]);
		printf("Case #%d: %s\n", i+1, tc->outcome);
	}
}


