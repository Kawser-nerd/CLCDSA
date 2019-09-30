#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// small:
//#define B 4
//#define N 16
//#define J 50

// large:
#define B 5
#define N 32
#define J 500

#define N_HIGHBIT (1 << (N-1))

const static uint8_t PRIMES[] = {
    // no jamcoin is a multiple of 2 in any base
    3, 5, 7, 11, 13, 17, 19, 23, 29, 31 // ...
};
static uint8_t *MODS[9];

static void set_mods() {
    #pragma unroll // whole function is constant
    for (int base=2; base<=10; base++) {
        #pragma unroll
        for (int pr=0; pr<sizeof(PRIMES)/sizeof(PRIMES[0]); pr++) {
            int result = 1;
            int bs = base % PRIMES[pr];
            #pragma unroll
            for (int i=0;i<B;i++) {
                result = result * bs % PRIMES[pr];
                bs = (bs * bs) % PRIMES[pr];
            }
            MODS[base-2][pr] = (PRIMES[pr] - result);
        }
    }
}

static uint8_t find_factor(int base, uint64_t x) {
    #pragma unroll // constant modulus optimizations
    for (int pr = 0; pr < sizeof(PRIMES) / sizeof(PRIMES[0]); pr++) {
        if (x % PRIMES[pr] == MODS[base-2][pr])
            return PRIMES[pr];
    }
    return 0;
}

static uint64_t try_coin(uint32_t num, uint8_t *factors) {
    uint64_t x; // numeric value of jamcoin in base
    #pragma unroll // multiplication by constant optimizations
    for (int base = 2; base <= 10; base++) {
        if (base == 2) {
            x = num;
        } else {
            x = 0;
            uint32_t n = num;
            uint64_t pval = 1;
            for (bool bit; bit = n & 1, n > 0; n >>= 1) {
                if (bit) {
                    x += pval;
                }
                pval *= base;
            }
        }
        uint8_t factor = find_factor(base, x);
        if (!factor)
            return 0;
        factors[base-2] = factor;
    }
    return x;
}

int main() {
    MODS[0] = malloc(sizeof(PRIMES) * 9);
    for (int i=1; i<9; i++) {
        MODS[i] = MODS[i-1] + sizeof(PRIMES);
    }
    set_mods();

    char y[32];
    int i;
    for (i=0; i<N-15; i++) {
        y[i] = '0';
    }
    y[i] = '\0';
    y[0] = '1';

    printf("Case #1:\n");
    uint8_t factors[9];
    for (int coingen=0, coins=0; coins<J; coingen++) {
        uint32_t n = (coingen << 1) + 1;
        uint64_t x = try_coin(n, factors);
        if (x) {
            printf("%s%015lu %hd %hd %hd %hd %hd %hd %hd %hd %hd\n", y, x,
                (short)factors[0], (short)factors[1], (short)factors[2],
                (short)factors[3], (short)factors[4], (short)factors[5],
                (short)factors[6], (short)factors[7], (short)factors[8]);
            coins++;
        }
    }
}
