#include <stdio.h>
#include <string.h>

enum { MAXN=100 };

int map[MAXN][MAXN];
int basins[MAXN][MAXN];
int W, H;

void read_map(void)
{
  int h;
  scanf("%d %d", &H, &W);
  for ( h=0; h<H; ++h )
  {
    int w;
    for ( w=0; w<W; ++w )
      scanf("%d", &map[h][w]);
  }
  memset(basins, 0, sizeof(basins));
}

int dh[] = { -1,  0, 0, 1 };
int dw[] = {  0, -1, 1, 0 };

int stackH[MAXN*MAXN], stackW[MAXN*MAXN];

inline int valid(int h, int w)
{
  return h >= 0 && h < H && w >=0 && w < W;
}

void calc_basins(void)
{
  int cb = 1;
  int h;
  for ( h=0; h<H; ++h )
  {
    int w;
    for ( w=0; w<W; ++w )
    {
      int nh = h, nw = w;
      int sp = 0;
      while ( basins[nh][nw] == 0 )
      {
        stackH[sp] = nh;
        stackW[sp++] = nw;
        int d, bestd = -1, bestv = map[nh][nw];
        for ( d=0; d<4; ++d )
        {
          int nnh = nh + dh[d], nnw = nw + dw[d];
          if ( valid(nnh, nnw) && map[nnh][nnw] < bestv )
          {
            bestv = map[nnh][nnw];
            bestd = d;
          }
        }
        if ( bestd < 0 )
          break;
        nh += dh[bestd];
        nw += dw[bestd];
      }
      int sinkno = basins[nh][nw] == 0 ? cb++ : basins[nh][nw];
      while ( sp > 0 )
      {
        nh = stackH[--sp];
        nw = stackW[sp];
        basins[nh][nw] = sinkno;
      }
    }
  }
}


void print_basin()
{
  int h;
  for ( h=0; h<H; ++h )
  {
    int w;
    for ( w=0; w<W; ++w )
    {
      if ( w > 0 )
        putchar(' ');
      putchar(basins[h][w] + 'a' - 1);
    }
    putchar('\n');
  }
}


int main()
{
  int T, t;
  scanf("%d", &T);
  for ( t=1; t<=T; ++t )
  {
    printf("Case #%d:\n", t);
    read_map();
    calc_basins();
    print_basin();
  }
  return 0;
}
