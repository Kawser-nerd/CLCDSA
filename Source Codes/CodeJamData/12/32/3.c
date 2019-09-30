#include <stdio.h>
#include <math.h>

double max(double a, double b) { return a>b?a:b; }

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    printf("Case #%d:\n", t);
    int n, A;
    double D;
    scanf("%lf %d %d", &D, &n, &A);
    double tm[n], x[n];
    for (int i=0; i<n; i++)
      scanf("%lf %lf", &tm[i], &x[i]);
    tm[n-1] = tm[n-2] + (D-x[n-2])/(x[n-1]-x[n-2])*(tm[n-1]-tm[n-2]);
    x[n-1] = D;
    for (int cas=0; cas<A; cas++)
    {
      double a;
      scanf("%lf", &a);
      double st = 0;
      for (int i=0; i<n; i++)
        st = max(st, tm[i] - sqrt(2*x[i]/a));
      printf("%lf\n", st + sqrt(2*D/a));
    }
  }
  return 0;
}
