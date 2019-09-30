#include <stdlib.h>
#include <stdio.h>

int
tobase(int n, int base, int columns[])
{
  int *p = columns;
  while (n) {
    *p++ = (n % base);
    n /= base;
  }
  return p - columns;
}

int
ishappy(long long n, int base)
{
  int columns[64];
  int nc;
  int i, count = 0;

  do {
    nc = tobase(n, base, columns);
    n = 0;
    for (i = 0; i < nc; i++) n += columns[i] * columns[i];
    count++;
    if (count >= 0x100) return 0;
  } while(n != 1);
  return count;
}

int
main(int argc, char **argv)
{
  int bases[10], nbases, ncase,i,j;
  long long n;
  

  scanf("%d\n", &ncase);

  for (i = 1; i <= ncase; i++) {
    char buffer[0x100], *p = buffer;
    fgets(buffer, sizeof(buffer), stdin);
    for (nbases = 0; (bases[nbases] = strtol(p, &p, 10));nbases++);

    n = 2;
    do {
      for (j = 0; j < nbases; j++) {
	if (!ishappy(n, bases[j])) break;
      }
      n++;
    } while (j < nbases);
    printf("Case #%d: %lld\n", i, --n);
  }
  return 0;
}
