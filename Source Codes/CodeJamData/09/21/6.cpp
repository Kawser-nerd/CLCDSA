#include <cstdio>
#include <set>
#include <string>

using namespace std;

#define mt 100000

int n, nv;
string ty[mt];
double pr[mt];
int l[mt], r[mt];
int c;

int readTree()
{
  int v = nv++;
  ty[v] = "";
  while (c != '(')
    c = getc(stdin);
  scanf("%lf", &pr[v]);
  c = getc(stdin);
  while (c != ')' && !('a' <= c && c <= 'z'))
    c = getc(stdin);
  if (c != ')')
  {
    while ('a' <= c && c <= 'z')
      ty[v] += c, c = getc(stdin);
    l[v] = readTree();
    r[v] = readTree();
    c = getc(stdin);
    while (c != ')')
      c = getc(stdin);
  }
  else
    l[v] = r[v] = -1;
  return v;
}

double get( int v, set <string> &s )
{
  if (l[v] == -1)
    return pr[v];
  if (s.count(ty[v]))
    return pr[v] * get(l[v], s);
  return pr[v] * get(r[v], s);
}

int main()
{
  int nt;
  scanf("%d", &nt);
  for (int tt = 1; tt <= nt; tt++)
  {
    printf("Case #%d:\n", tt);
    nv = 0;
    scanf("%*d");
    c = -1;
    readTree();
    scanf("%d", &n);
    while (n--)
    {
      int k;
      scanf("%*s%d", &k);
      set <string> cu;
      while (k--)
      {
        char s[99];
        scanf("%s", s);
        cu.insert(s);
      }
      printf("%.9lf\n", get(0, cu));
    }
  }
  return 0;
}
