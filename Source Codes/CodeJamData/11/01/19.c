#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a)<0 ? -(a) : (a))
#define MAX(a, b) ((a)>(b) ? (a) : (b))

int main()
{
  int T, N;
  int i, j;
  int po, pb, to, tb;
  char c;
  int d;
  int l, s;

  scanf("%d", &T);

  for (i = 0; i < T; i++) {
    scanf("%d", &N);

    po = pb = 1;
    to = tb = 0;
    s = 0;
    for (j = 0; j < N; j++) {
      do {
	scanf("%c", &c);
      } while (c != 'O' && c != 'B');
      if (c == 'O') {
	scanf("%d", &d);
	l = MAX(ABS(po - d) - to, 0);
	to = 0;
	po = d;
	s += l + 1;
	tb += l + 1;
      }
      if (c == 'B') {
	scanf("%d", &d);
	l = MAX(ABS(pb - d) - tb, 0);
	tb = 0;
	pb = d;
	s += l + 1;
	to += l + 1;
      }
    }

    printf("Case #%d: ", i+1);
    printf("%d\n", s);
  }

  return 0;
}
