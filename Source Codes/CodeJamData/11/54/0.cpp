#include <iostream>
using namespace std;

int main()
{
  int N; scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    {
      char z[70];
      scanf("%s", z);
      int zl = strlen(z);
      int k = (zl + 1) >> 1;
      int lwr = 1 << (k - 1);
      int upr = 1 << (k);
      long long x = 0;
      fprintf(stderr, "%s\n", z);
      for (int r = lwr; r < upr; ++r)
	{
	  long long x = ((long long) r) * r;
	  bool ok = true;
	  for (int k = 0; (ok) && (k < zl); ++k)
	    ok = ((z[k] == '?') || ((z[k] - 48) == ((x >> (zl - (k + 1))) & 1)));
	  if (ok)
	    {
	      printf("Case #%d: ", i);
	      for (int k = 0; k < zl; ++k)
		printf("%d", (int)((x >> (zl - (k + 1))) & 1));
	      printf("\n");
	      break;
	    }
	}
    }
}
