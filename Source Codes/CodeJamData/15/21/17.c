#include <stdio.h>

//reverse an integer
long long flip(long long a) {
  long long new = 0;
  while (a != 0) {
    new = new*10 + (a%10);
    a /= 10;
  }
  return new;
}

// a > 0
int len(int a) {
  int len = 0;
  while (a != 0) {
    len++;
    a /= 10;
  }
  return len;
}

// fast exponentiation. exp should be positive.
long long intpow(int base, int exp) {
  long long result = 1;
  while (exp) {
    if (exp&1)
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

// returns number of steps to get from minimum number of length l-1 (i.e.
// 10^(l-2)) to min number of len l-2 (i.e. 10^(l-1))
long long lenSteps(int l) {
  return intpow(10, (l-1)/2) + intpow(10, l/2) - 1;
}

// for an int a of length l, returns first l/2 (int division) digits
int firstHalf(int a) {
  return a / intpow(10, (len(a)+1)/2);
}

// for an int a of length l, returns last (l+1)/2 (int division) digits
int secHalf(int a) {
  return a % intpow(10, (len(a)+1)/2);
}

int main() {
  int T, i, goalLen, flipFirstHalf, lastHalf, tmp;
  long long N, t;
  FILE *fin = fopen("A-counter.in", "r");
  FILE *fout = fopen("A-counter.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    t = 0;
    fscanf(fin, "%lld\n", &N);
    if (N < 10) fprintf(fout, "Case #%d: %lld\n", i, N);
    else {
      goalLen = len(N);
      tmp = goalLen;
      while (tmp > 1) {
        t += lenSteps(tmp);
        tmp--;
      }
      flipFirstHalf = flip(firstHalf(N));
      lastHalf = secHalf(N);
      if (lastHalf == 0 && flipFirstHalf > 1) { // edge case
        flipFirstHalf = flip(firstHalf(N)-1);
        if (flipFirstHalf == 1) t--;
        t += flipFirstHalf;
        t += intpow(10, (goalLen+1)/2);
      }
      else {
        if (flipFirstHalf > 1) t += flipFirstHalf; // +1 for flip but then -1 in sec half
        t += lastHalf;
      }
      fprintf(fout, "Case #%d: %lld\n", i, t);
    }
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
