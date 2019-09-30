#include <stdio.h>

int main() {
  int Q;
  int T;

  scanf(" %d", &T);

  for (Q = 1; Q <= T; Q++) {
    int N;
    int P;

    scanf(" %d", &N);
    scanf(" %d", &P);

    int g[105];

    int i;

    for (i = 0; i < N; i++) {
      scanf(" %d", &g[i]);
    }

    int result;

    if (P == 2) {
      int odds = 0;
      int evens = 0;

      for (i = 0; i < N; i++) {
	if (g[i] % 2) {
	  odds++;
	} else {
	  evens++;
	}
      }

      if (odds == 0) {
	result = evens;
      } else if (odds % 2) {
	result = evens + odds / 2 + 1;
      } else {
	result = evens + odds / 2;
      }
    } else if (P == 3) {
      int evens = 0;
      int pluses = 0;
      int minuses = 0;

      for (i = 0; i < N; i++) {
	if (g[i] % 3 == 1) {
	  pluses++;
	} else if (g[i] % 3 == 2) {
	  minuses++;
	} else {
	  evens++;
	}
      }

      result = evens;

      int pairs;
      int triples;

      if (pluses < minuses) {
	pairs = pluses;
	triples = minuses - pluses;
      } else {
	pairs = minuses;
	triples = pluses - minuses;
      }

      if (pairs) {
	result += pairs;
      }

      if (triples) {
	if (triples % 3) {
	  result += triples / 3 + 1;
	} else {
	  result += triples / 3;
	}
      }
    } else if (P == 4) {
      // more stuff

      int evens = 0;
      int pluses = 0;
      int halves = 0;
      int minuses = 0;

      for (i = 0; i < N; i++) {
	if (g[i] % 4 == 1) {
	  pluses++;
	} else if (g[i] % 4 == 2) {
	  halves++;
	} else if (g[i] % 4 == 3) {
	  minuses++;
	} else {
	  evens++;
	}
      }

      result = evens;

      int pairs = halves / 2;
      int rems;

      if (pluses < minuses) {
	pairs += pluses;
	rems = minuses - pluses;
      } else {
	pairs += minuses;
	rems = pluses - minuses;
      }

      if (pairs) {
	result += pairs;
      }

      if (halves % 2) {
	result++;
	rems -= 2;
      }

      if (rems > 0) {
	if (rems % 4) {
	  result += rems / 4 + 1;
	} else {
	  result += rems / 4;
	}
      }
    }

    printf("Case #%d: %d\n", Q, result);
  }
}
