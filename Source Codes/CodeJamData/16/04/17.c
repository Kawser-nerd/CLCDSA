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

// solver
void solve_instance(int k, int c, int s) {
  // if ceil(k, c) <= s, problem is solvable, else not
  int necessary_tiles = (k + c - 1) / c;
  if(necessary_tiles > s) {
    printf(" IMPOSSIBLE");
  } else {
    // print out a series of tiles
    // abstract so fractals are a tree
    // at each level, take a path of a different child index
    int idx = 0;
    for(int i = 0; i < necessary_tiles; i++) {
      unsigned long long tile_num = 0;

      for(int j = 0; j < c; j++) {
        tile_num = tile_num * k + idx;
        idx = (idx + 1) % k;
      }

      // tiles are 1-based indexing
      tile_num++;

      // print out answer
      printf(" %llu", tile_num);
    }
  }
}

// main function
int main(int argc, char* argv[]) {
  // get instance count
  int t = next_int();

  // solve each instance
  for(int i = 1; i <= t; i++) {
    // print prefix
    printf("Case #%d:", i);

    // get parameters
    int k = next_int();
    int c = next_int();
    int s = next_int();

    // solve
    solve_instance(k, c, s);

    // add final newline
    printf("\n");
  }
}

