#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxL = 1000 + 10;

long long F[maxL];
long long ans;
int P, K, L, data;

void getinf()
{
  scanf("%d%d%d", &P, &K, &L);
  for (int i = 0; i < L; i++)
    {
      cin >> F[i];
    }
}

bool solve()
{
  if (P * K < L) return 0;
  sort(F, F + L);
  ans = 0;
  for (int i = 1, k = L - 1; k >= 0; i++)
    {
      for (int j = 0; j < K && k >= 0; j++, k--)
	{
	  ans += F[k] * i;
	}
    }
  return 1;
}

int main()
{
  scanf("%d", &data);
  for (int tot = 1; tot <= data; tot++)
    {
      getinf();
      if (solve()) printf("Case #%d: ", tot), cout << ans << endl;
      else printf("Case #%d: Impossible\n", tot);
    }
}
