#include <stdlib.h>
#include <stdio.h>

// get an integer from stdin
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

int main(int argc, char* argv[]) {
  // get the input count
  int t = next_int();

  // iterate over the problems
  for(int i = 1; i <= t; i++) {
    // print prefix for problem
    printf("Case #%d: ", i);

    // solve the problem
    // smallest number of flips is number of switch points in the sequence
    // if a '+' is placed at the end
    // ex. +-+- to +-+-(+) has 4 changes, hence requires 4 flips

    // 1. find the next expected character
    int pancake;
    do {
      pancake = getchar();
    } while(pancake != '+' && pancake != '-' && pancake != EOF);

    // error out
    if(pancake == EOF)
      break;

    // 2. iterate and count the number of switch points
    int previous = pancake;
    int flips = 0;
    for(;;) {
      pancake = getchar();
      if(!(pancake == '+' || pancake == '-')) break;
      if(previous != pancake) {
        previous = pancake;
        flips++;
      }
    }

    // 3. check for final flip (add a '+' to the end and count that switch)
    if(previous == '-') {
      flips++;
    }

    // 4. print out solution
    printf("%d\n", flips);
  }
}

