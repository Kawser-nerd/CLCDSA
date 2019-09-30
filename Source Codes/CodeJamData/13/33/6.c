#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int time, west, east, strength;
} ATTACK;

ATTACK attack[100];

int a[20000];

int cmp(const void *a, const void *b)
{
  const ATTACK* aa = (const ATTACK*)a;
  const ATTACK* bb = (const ATTACK*)b;
  return aa->time - bb->time;
}

int check(int w, int e, int s)
{
  for (int i=w; i<e; i++)
    if (a[i] < s)
      return 1;
  return 0;
}

int max(int a, int b)
{
  return a >= b ? a : b;
}

void update(int w, int e, int s)
{
  for (int i=w; i<e; i++)
    a[i] = max(a[i], s);
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int n;
    scanf("%d", &n);
    int attacks = 0;
    for (int i=0; i<n; i++)
    {
      int ni, di, wi, si, ei, ddi, dpi, dsi;
      scanf("%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &ddi, &dpi, &dsi);
      for (int j=0; j<ni; j++)
      {
        attack[attacks].time = di;
        attack[attacks].west = wi + 10000;
        attack[attacks].east = ei + 10000;
        attack[attacks].strength = si;
        attacks++;
        di += ddi;
        wi += dpi;
        ei += dpi;
        si += dsi;
      }
    }
    qsort(attack, attacks, sizeof(ATTACK), cmp);

    memset(a, 0, sizeof(a));
    int res = 0;
    int i = 0;
    while(i < attacks)
    {
      int curtime = attack[i].time;
      for (int j=i; j<attacks && attack[j].time == curtime; j++)
        res += check(attack[j].west, attack[j].east, attack[j].strength);
      for (int j=i; j<attacks && attack[j].time == curtime; j++, i++)
        update(attack[j].west, attack[j].east, attack[j].strength);
    }
    
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
