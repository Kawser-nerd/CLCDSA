#include <stdlib.h>
#include <stdio.h>

// utility :: get an integer from stdin
int next_int() {
  int ret = 0, nx;

  // skip nondigits
  do {
    nx = getchar();
  } while(nx != EOF && (nx < '0' || '9' < nx));

  // break if EOF reached
  if(nx == EOF) return 0;

  // standard digit conversion (ignore -'s)
  do {
    ret = 10 * ret + nx - '0';
    nx = getchar();
  } while('0' <= nx && nx <= '9');

  // return number
  return ret;
}

void print_binary(unsigned long long val, unsigned long n) {
  for(unsigned long long msk = (0x01ull << (n-1)); msk; msk >>= 1) {
    if(val & msk) {
      printf("1");
    } else {
      printf("0");
    }
  }
}

// solve instances
// note: for 2k bits, this method yields 2^(k-2) possible coins, so the
//       example (6 3) from the problem page will not work...
// note: only works for EVEN n
void solve_instance(int n, int j) {
  // get k : n = 2k
  int k = n / 2;

  // get a generator and pattern set
  // ex. n = 6, k = 3
  //   generator     = 001001
  //   pattern_frame = 000101
  //   pattern_mask  = 000001
  // then pattern_mask covers k-2 bits, which can be placed into the frame
  //   pattern_mask -> 00000x
  //   full_pattern -> 0001x1
  // then multiplying by generator yields valid jamcoin
  //   1x11x1
  // we have the divisors, so convert to proper base

  unsigned long long generator = 1 + (1 << k);
  unsigned long long pattern_frame = 1 + (1 << (k-1));
  unsigned long long pattern_mask = (1 << (k - 2)) - 1;

  // iterate over potential jam coins
  for(int i = 0; i < j; i++) {
    unsigned long long divisor = ((i & pattern_mask) << 1) | pattern_frame;
    unsigned long long jamcoin = generator * divisor;

    // print out the jamcoin
    print_binary(jamcoin, n);

    // print out divisor in each base
    for(int base = 2; base <= 10; base++) {
      unsigned long long val = 0;
      unsigned long long digit_val = 1;

      unsigned long long limit = (1 << k);
      for(unsigned long long msk = 1; msk < limit; msk <<= 1) {
        if(divisor & msk) {
          val += digit_val;
        }
        digit_val *= base;
      }

      // print out divisor
      printf(" %llu", val);
    }

    // newline to separate coins
    printf("\n");
  }
}

// main function
int main(int argc, char* argv[]) {
  // get number of problems
  int t = next_int();

  // perform tests
  for(int i = 1; i <= t; i++) {
    // print prefix
    printf("Case #%d: \n", i);

    // get parameters
    int n = next_int();
    int j = next_int();

    // solve the instance
    solve_instance(n, j);
  }
}

