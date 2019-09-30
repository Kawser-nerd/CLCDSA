#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
  int nt;
  scanf("%d", &nt);
  for (int tt = 1; tt <= nt; tt++)
  {
    char s[99];
    scanf("%s", s);
    int l = strlen(s);
    if (!next_permutation(s, s + l))
    {
      int j = -1;
      for (int i = 0; i < l; i++)
        if (s[i] != '0' && (j == -1 || s[j] > s[i]))
          j = i;
      swap(s[j], s[0]);
      s[l++] = '0';
      s[l] = 0;
      sort(s + 1, s + l);
    }
    printf("Case #%d: %s\n", tt, s);
  }
  return 0;
}
