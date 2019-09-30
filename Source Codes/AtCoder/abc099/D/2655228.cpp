#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>

using std::list;
using std::max;
using std::min;
using std::vector;

long long color_table[31][31];
long long cell[501][501];

long long cost[3][31];

void try_color(int edge_len, int group, int color)
{
  for(int x = 1; x <= edge_len; x++) {
    for(int y = 1; y <= edge_len; y++) {
      int remainder = (x + y) % 3;
      if(remainder != group) {
        continue;
      }
      cost[group][color] += color_table[cell[x][y]][color];
    }
  }
}

void try_all_color(int edge_len, int group, int ncolor)
{
  for(int color = 1; color <= ncolor; color++) {
    try_color(edge_len, group, color);
  }
}

void try_all_groups(int edge_len, int ncolor)
{
  for(int group = 0; group < 3; group++) {
    try_all_color(edge_len, group, ncolor);
  }
}

long long solve(int edge_len, int ncolor)
{
  try_all_groups(edge_len, ncolor);
  long long result = LLONG_MAX;
  for(int x = 1; x <= ncolor; x++) {
    for(int y = 1; y <= ncolor; y++) {
      for(int z = 1; z <= ncolor; z++) {
        if(x == y || y == z || z == x) { // not a permutation
          continue;
        }
        result = min(result, cost[0][x] + cost[1][y] + cost[2][z]);
      }
    }
  }
  return result;
}

void init_arrays()
{
  memset(cost, 0, sizeof(cost));
}

int main()
{
  int edge_len, ncolor;
  scanf("%d%d", &edge_len, &ncolor);
  for(int x = 1; x <= ncolor; x++) {
    for(int y = 1; y <= ncolor; y++) {
      scanf("%lld", &color_table[x][y]);
    }
  }
  for(int x = 1; x <= edge_len; x++) {
    for(int y = 1; y <= edge_len; y++) {
      scanf("%lld", &cell[x][y]);
    }
  }
  printf("%lld\n", solve(edge_len, ncolor));
  return 0;
}