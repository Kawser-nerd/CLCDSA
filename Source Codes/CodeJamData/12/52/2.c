#include <stdio.h>
#include <string.h>

int S;
const char *state[] = { "", "ring", "fork", "fork-ring", "bridge", "bridge-ring", "bridge-fork", "bridge-fork-ring" };
char map[2*3000][2*3000];

int corners;
int edges;

void search(int a, int b)
{
  if (a < 1 || a >= 2*S || b < 1 || b >= 2*S || b-a > S-1 || a-b > S-1)
    return;
  if (map[a][b] != 1)
    return;
  map[a][b] |= 2;

  if (a == 1)
    if (b == 1)
      corners |= 1;
    else if (b == S)
      corners |= 2;
    else
      edges |= 1;

  if (b - a == S-1)
    if (a == 1)
      corners |= 2;
    else if (a == S)
      corners |= 4;
    else
      edges |= 2;
  
  if (b == 2*S-1)
    if (a == S)
      corners |= 4;
    else if (a == 2*S-1)
      corners |= 8;
    else
      edges |= 4;
  
  if (a == 2*S-1)
    if (b == 2*S-1)
      corners |= 8;
    else if (b == S)
      corners |= 16;
    else
      edges |= 8;
  
  if (a - b == S-1)
    if (b == S)
      corners |= 16;
    else if (b == 1)
      corners |= 32;
    else
      edges |= 16;
  
  if (b == 1)
    if (a == S)
      corners |= 32;
    else if (a == 1)
      corners |= 1;
    else
      edges |= 32;
  
  search(a+1, b);
  search(a, b+1);
  search(a-1, b);
  search(a, b-1);
  search(a-1, b-1);
  search(a+1, b+1);
}

int ringer(int a, int b)
{
  if (a < 1 || a >= 2*S || b < 1 || b >= 2*S || b-a > S-1 || a-b > S-1)
    return 1;
  if (map[a][b] != 0)
    return 0;
  map[a][b] |= 4;
  return ringer(a+1, b) || ringer(a+1,b+1) || ringer(a,b+1) || ringer(a-1, b) || ringer(a-1, b-1) || ringer(a, b-1);
}

int doring(int a, int b)
{
  if (a < 1 || a >= 2*S || b < 1 || b >= 2*S || b-a > S-1 || a-b > S-1)
    return 0;
  if (map[a][b] != 0)
    return 0;
  return !ringer(a,b);
}

int popcnt[64];

int main()
{
  popcnt[0] =0;
  for (int i=1; i<64; i++)
    popcnt[i] = popcnt[i/2] + (i&1);

  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    int M;
    scanf("%d %d", &S, &M);
    
    int done = 0;
    int domove = 0;
    memset(map, 0, sizeof(map));
    for (int m=0; m<M; m++)
    {
      int a, b;
      scanf("%d %d", &a, &b);
      if (done)
        continue;

      map[a][b] = 1;
      corners = 0;
      edges = 0;
      search(a, b);
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;
      if (popcnt[edges] >= 3)
        done |= 2;
      if (popcnt[corners] >= 2)
        done |= 4;

      if (doring(a+1, b))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (doring(a+1, b+1))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (doring(a, b+1))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (doring(a-1, b))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (doring(a-1, b-1))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (doring(a, b-1))
        done |= 1;
      for (int i=1; i < 2*S; i++)
        for (int j=1; j < 2*S; j++)
          map[i][j] &= 1;

      if (done)
        domove = m+1;
    }
    
    printf("Case #%d: ", t);
    if (!done)
      printf("none\n");
    else
      printf("%s in move %d\n", state[done], domove);
  }
  return 0;
}
