#include <algorithm>
#include <cstdio>

using namespace std;

#define maxn 808

int n;
int x[maxn], y[maxn];

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int test = 1; test <= tn; test++)
  {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &x[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &y[i]);
    sort(x, x + n);
    sort(y, y + n);
    reverse(y, y + n);
    long long ans1 = 0;
    for (int i = 0; i < n; i++)
      ans1 += (long long)x[i] * y[i];
/*    long long ans2 = (long long)1 << 60;
    do
    {
      long long temp = 0;
      for (int i = 0; i < n; i++)
        temp += (long long)x[i] * y[i];
      ans2 = min(ans2, temp);
    } while (next_permutation(x, x + n));
    if (ans2 != ans1)
      fprintf(stderr, "bug!\n");*/
    printf("Case #%d: %Ld\n", test, ans1);
  }
  return 0;
}
