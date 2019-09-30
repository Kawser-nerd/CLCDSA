#include <stdio.h>
#include <string.h>

enum { N = 99999999 };

signed char happy[N + 1];
int stack[N + 1];

int next_step(int x, int base)
{
  int r = 0;
  while ( x > 0 )
  {
    int d = x % base;
    x /= base;
    r += d*d;
  }
  return r;
}

void fill_happy(int base)
{
  int i;
  memset(happy, 0, sizeof(happy));
  happy[1] = 1;
  for ( i=2; i<=N; ++i )
  {
    int ni = i, sp = 0;
    while ( happy[ni] == 0 )
    {
      stack[sp++] = ni;
      happy[ni] = 2;
      ni = next_step(ni, base);
    }
    int nv = happy[ni] == 2 ? -1 : happy[ni];
    while ( sp > 0 )
      happy[stack[--sp]] = nv;
  }
}


int numbers[N + 1];

void fill_numbers(void)
{
  int b;
  for ( b=2; b<=10; ++b )
  {
    fprintf(stderr, "base = %d\n", b);
    fill_happy(b);
    int i, m = 1<<(b - 2);
    for ( i=1; i<=N; ++i )
      if ( happy[i] == 1 )
        numbers[i] |= m;
  }
}


int main()
{
  fill_numbers();
  int i;
  for ( i=1; i<=N; ++i )
    printf("%d\n", numbers[i]);

  return 0;
}
