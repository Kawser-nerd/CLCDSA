#include <stdint.h>
#include <stdio.h>
#include <cmath>

#include <iostream>

inline uint64_t incr(uint64_t x) {
    uint64_t increr = 1;
    uint64_t ander = 15;
    uint64_t cmper = 9;
    if ((x & ander) != cmper) {
	x += increr;
	return x;
    }

    x &= ~ander;
    ander <<= 4;
    cmper <<= 4;
    increr <<= 4;

    while ((x & ander) == cmper) {
	x &= ~ander;
	ander <<= 4;
	cmper <<= 4;
	increr <<= 4;
    }

    x += increr;
    return x;
}

int main() {
    int num_cases;
    std::cin >> num_cases;
    for (int casenum = 1; casenum <= num_cases; ++casenum) {
	int a, b;
	std::cin >> a >> b;

	char dat[1];

	int a_size = snprintf(dat, 1, "%d", a);
	int b_size = snprintf(dat, 1, "%d", b);
	int sz = a_size;

	uint64_t count = 0;

	int lo = a;
	int hi = b;

	uint64_t p_lo = 0;
	for (int i = 0; i < sz; ++i) {
	    p_lo |= (lo % 10) << (4 * i);
	    lo /= 10;
	}

	uint64_t p_hi = 0;
	for (int i = 0; i < sz; ++i) {
	    p_hi |= (hi % 10) << (4 * i);
	    hi /= 10;
	}

	uint64_t mask = (1 << (4 * sz)) - 1;

	for (uint64_t x = p_lo; x <= p_hi; x = incr(x)) {
	    uint64_t considered[12];
	    for (int i = 1; i < sz; ++i) {
		uint64_t tmp = (x >> (4 * i)) | (x << (4 * (sz - i)));
		tmp &= mask;
		considered[i] = tmp;
		if (x < tmp && tmp <= p_hi) {
		    considered[i] = tmp;
		    for (int j = 1; j < i; ++j) {
			if (considered[j] == tmp) {
			    goto no_count;
			}
		    }

		    count += 1;
		no_count:
		    ;
		}
	    }

	}

	std::cout << "Case #" << casenum << ": " << count << "\n";
    }
}
